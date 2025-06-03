# Import and Export Company Management System

A comprehensive C++ application for managing import and export company operations, built with Qt framework.

## Overview

This system provides a complete solution for managing various aspects of an import/export company, including:
- User management and authentication
- Product and inventory management
- Order processing
- Shipment tracking
- Employee management
- Category management
- Promotional code handling
- Vehicle fleet management
- Account management
- Shopping cart functionality

## Features

- **User Management**: Complete user authentication and authorization system
- **Inventory Control**: Track products, stock levels, and categories
- **Order Processing**: Manage customer orders and track their status
- **Shipment Tracking**: Monitor shipments and delivery status
- **Employee Management**: Handle employee records and access levels
- **Category Management**: Organize products into categories
- **Promotional System**: Implement and manage promotional codes
- **Vehicle Management**: Track company vehicles and their assignments
- **Account Management**: Handle financial accounts and transactions
- **Shopping Cart**: Process customer orders through a cart system

## Technical Details

### Prerequisites

- C++ compiler with C++11 or later support
- Qt Framework
- SQLite database
- Visual Studio (for Windows development)

### Project Structure

The project is organized into several key components:

- **Core Classes**:
  - `User`: User management and authentication
  - `Product`: Product information and management
  - `Inventory`: Stock and inventory control
  - `Order`: Order processing and management
  - `Shipment`: Shipment tracking and management
  - `Employee`: Employee information and management
  - `Category`: Product categorization
  - `Promocode`: Promotional code handling
  - `Vehicle`: Vehicle fleet management
  - `Account`: Financial account management
  - `Cart`: Shopping cart functionality

- **Support Classes**:
  - `Date`: Date handling and management
  - `Person`: Base class for user-related entities
  - `SystemStart`: System initialization and setup

### Database

The system uses SQLite for data persistence, with database files stored in the `DB` directory.

## Building and Running

1. Clone the repository
2. Open the solution file in Visual Studio
3. Build the project
4. Run the executable

## File Structure

- `*.cpp` and `*.h` files contain the core implementation and header files
- `*.ui` files contain the Qt Designer UI definitions
- `*.qrc` files manage Qt resources
- `DB/` directory contains database files
- `media/` directory contains application resources

## Contributing

1. Fork the repository
2. Create a feature branch
3. Commit your changes
4. Push to the branch
5. Create a Pull Request

## License

This project is proprietary software. All rights reserved.

## Support

For support and questions, please contact the development team. 