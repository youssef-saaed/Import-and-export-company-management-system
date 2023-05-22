#include "Category.h"

Category::Category(){
	setNumOfProducts(0);
}

Category::Category(Category* cCategory)
{
	this->name = cCategory->getName();
	this->description = cCategory->getDescription();
	this->image = cCategory->getImage();
	this->tags = cCategory->getTags();
}

Category::Category(const std::string& name, const std::string& description, const std::string& tags, const std::string& image, Product* products) {
	setName(name);
	setDescription(description);
	setTags(tags);
	setImage(image);
	setProducts(products);
}

Category::~Category()
{
}



bool Category::setName(const std::string& name) {
	if (name != " ") {
		this->name = name;
		return true;
	}return false;
}

std::string Category::getName() const{
	return name;
}

bool Category::setDescription(const std::string& description) {
	if (description != " ") {
		this->description = description;
		return true;
	}return false;
}

std::string Category::getDescription() const {
	return description;
}

bool Category::setTags(const std::string& tags) {
	if (tags != " ") {
		this-> tags = tags;
		return true;
	}return false;
}
std::string Category::getTags() const {
	return tags;
}

bool Category::setImage(const std::string& image)
{
	if (image != " ") {
		this->image = image;
		return true;
	}return false;
}

std::string Category::getImage() const
{
	return image;
}

bool Category::setProducts(Product* products)
{
	if (products) {
		this->products = products;
		return true;
	}return false;
}

Product* Category::getProducts() const
{
	return products;
}

std::string Category::check()
{	
	if (name == "") return "name is required";
	std::regex namePattern("[A-Za-z\\d\\s]+");
	if (!std::regex_match(name, namePattern)) {
		return "letters and space are only allowed in name";
	}
	if (description == "") return "description is required";
	if (!std::regex_match(description, namePattern)) {
		return "letters and space are only allowed in description";
	}
	if (tags == "") return "At least one tag is required";
	std::regex tagsPattern("[A-Za-z\\s\\-\\d]+");
	if (!std::regex_match(tags, tagsPattern)) {
		return "write tags seperated with (-) only";
	}
	if (image == "" or image[image.length() - 1] == '/') {
		return "picture is required";
	}
	return "looks good";
}

bool Category::setNumOfProducts(const int&n)
{
	numOfProducts = n;
	return true;
}

int* Category::search(std::string searchWord)
{
	int* res = new int[numOfProducts + 1];
	res[0] = 0;
	for (int i = 0; i < numOfProducts; i++) {
		std::string pData[2] = {products[i].getName(),products[i].getDescription()};
		for (std::string str : pData) {
			std::string lowered;
			for (int j = 0; j < str.length(); j++) lowered += std::tolower(str[j]);
			if (lowered.find(searchWord) >= 0 and lowered.find(searchWord) < lowered.length()) {
				res[0]++;
				res[res[0]] = i;
				break;
			}
		}
	}
	int* res2 = new int[res[0] + 1];
	res2[0] = res[0];
	for (int i = 1; i <= res[0]; i++) res2[i] = res[i];
	delete[] res;
	return res2;
}

int Category::getNumOfProducts() const
{
	return numOfProducts;
}

void Category::writeToCsv()
{
	std::ifstream reader;
	reader.open("./DB/categories.csv");
	std::string file = "", line;
	while (std::getline(reader, line)) {
		file += line + '\n';
	}
	file += name + ',' + description + ',' + tags + ',' + image + ",\n";
	reader.close();

	int newCount;

	reader.open("./DB/categories count.txt");
	std::getline(reader, line);
	newCount = QString::fromStdString(line).toInt() + 1;
	reader.close();

	std::ofstream writer;
	writer.open("./DB/categories.csv");
	writer << file;
	writer.close();

	writer.open("./DB/categories count.txt");
	writer << newCount;
	writer.close();

}

