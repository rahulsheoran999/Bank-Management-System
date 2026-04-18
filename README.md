🏦 Bank Management System

Description

      The **NOVA Bank Management System** is a robust, terminal-based C++ application designed to simulate real-world banking workflows. It provides a secure and modular environment for managing
      
      user accounts, performing financial transactions, and maintaining persistent data storage using file-handling techniques.

      This project demonstrates core programming fundamentals including structured data management, modular software design, and secure input handling.

✨ Features

👤 Account Management

      Create Account: Generate unique account numbers (NOVA1001+) with automated timestamping.
      
      Account Details: View complete profiles including contact info, account type, and status.
      
      Change PIN: Securely update account access codes with identity verification.
      
      Close Account: Logic for soft-deleting/deactivating accounts.

💰 Transaction Handling

      Deposit & Withdraw: Real-time balance updates with a minimum balance enforcement (₹500).
      
      Fund Transfer: Transfer money between two internal accounts with dual-log updates.
      
      Transaction History: View a formatted chronological log of all deposits, withdrawals, and transfers.
      
      Mini Statement: Quick access to the most recent account activity.

📄 Data Management

      Store account data using files
      Read and update stored records
      Persistent storage without database

🔐 Security & Validation

      Masked PIN Input:** Prevents shoulder-surfing by hiding characters during entry.
      
      Identity Verification: Critical operations (Withdraw, Details, PIN 
      change) require a multi-attempt PIN check.
      Buffer Management: Robust input handling to prevent menu skipping and program crashes.



📂 Project Folder Structure

     bank-management/
      │
      ├── main.cpp                # Entry point & Menu navigation
      ├── include/                # Header files (.h)
      │   ├── account.h           # Account logic declarations
      │   ├── transaction.h       # Financial operation declarations
      │   ├── filehandling.h      # Data persistence logic
      │   ├── models.h            # Transaction & Account Structs
      │   └── utils.h             # UI/UX & Helper tools
      ├── src/                    # Implementation files (.cpp)
      │   ├── account.cpp         
      │   ├── transaction.cpp     
      │   ├── filehandling.cpp    
      │   └── utils.cpp           
      ├── accounts.dat            # Persistent account database
      ├── transactions.dat        # Persistent transaction ledger
      └── README.md

🛠️ Tech Stack
      
      Language: C++11 or higher

      Data Structures: Struct-based models for complex data mapping.

      File Handling: Stream-based I/O for persistent .dat records.

      Modular Programming: Separation of concerns across multiple source and header files.

⚙️ Installation & Setup

      1. Clone the repository
      git clone https://github.com/your-username/bank-management.git
      cd bank-management
      2. Compile the project
      g++ src/*.cpp main.cpp -Iinclude -o bank
      3. Run the application
      ./bank

▶️ Usage

      Create a new account
      Perform deposit or withdrawal
      Check account details
      Data is saved automatically in files
      
📸 Screenshots

      (Add screenshots of your program output here)

🌱 Future Improvements

      Encryption: Implement AES-256 encryption for PIN storage in .dat files.

      Database Migration: Move from flat files to SQLite for better query performance.

      Graphical Interface: Develop a GUI version using the Qt Framework.

      Admin Dashboard: Add a "Manager Mode" to view bank-wide total liquidity and user stats.
      
🤝 Contributing

      Contributions are welcome!
      Feel free to fork the repository and submit a pull request.

👨‍💻 Author

      Rahul C++ Developer & Tech Enthusiast

📄 License

      This project is licensed under the MIT License.
