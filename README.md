# Personal Organizer

A desktop application built with C++/CLI to help you manage your personal finances and tasks. This application provides a user-friendly interface to track your income and expenses, set budgets, and manage your to-do list.

---

## Features

- **User Authentication:** Secure login and registration system with AES password encryption.
- **Dashboard:** Central dashboard to view user details and a summary chart of your budget vs. expenses.
- **Expense & Income Tracking:** Add and view daily expenses and income, categorized.
- **Budget Management:** Set monthly budgets for different expense categories.
- **Task Management:** Create and view tasks with due dates and times.
- **Reporting:** Generate monthly and custom date-range reports of your financial activity.
- **User Profile:** View and update your personal details.
- **Notifications:** Get reminders for upcoming tasks.

---

## Getting Started

### Prerequisites

- **Visual Studio:** Required to open and build the project.
- **SQL Server:** An instance of SQL Server is required to set up the database. The connection string in the project points to `THARINDA\SQLEXPRESS`. You may need to change this in `DBConnection.h`.
- **.NET Framework:** The project targets the .NET Framework 4.7.2.

### Installation

1. **Clone the repository:**
    ```sh
    git clone https://github.com/Tharinda-Pamindu/PersonalOrganizer.git
    ```
2. **Database Setup:**
    - Open SQL Server Management Studio.
    - Create a new database named **PersonalOrganiser**.
    - Execute the SQL scripts to create the necessary tables (`users`, `income`, `expense`, `toDo`, `budget`). *Note: The SQL scripts are not included in the provided files but are required for a full setup.*
3. **Open in Visual Studio:**
    - Open the `PersonalOrganizer.sln` file in Visual Studio.
4. **Update Connection String:**
    - Open the `DBConnection.h` file.
    - Modify the `SqlConnection` string to match your SQL Server instance if needed.
5. **Build and Run:**
    - Build the solution.
    - Run the application.

---

## Usage

1. **Register:** Create a new user account.
2. **Login:** Sign in with your credentials.
3. **Dashboard:** Access the main dashboard after logging in.
4. **Add Expense/Income:** Use the respective buttons to add new financial entries.
5. **Set Budget:** Navigate to the budget section to set monthly spending limits for various categories.
6. **Manage Tasks:** Add new tasks to your to-do list and view them.
7. **Generate Reports:** Use the reporting feature to get insights into your finances.

---

## Built With

- **C++/CLI:** Core language for the project.
- **Windows Forms:** For the graphical user interface.
- **SQL Server:** Database for storing user data.
- **AES Encryption:** For secure password storage.

---

## Contributing

Contributions are welcome! Please fork the repository and submit pull requests for any improvements or bug fixes. For major changes, open an issue first to discuss what you would like to change.

---

## License

This project currently does not specify a license.

---

## Author

- [**Tharinda Pamindu**](https://github.com/Tharinda-Pamindu)
