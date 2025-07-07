# Personal Organizer

A desktop application built with C++/CLI to help you manage your personal finances and tasks. This application provides a user-friendly interface to track your income and expenses, set budgets, and manage your to-do list.

-----

## Features

  * **User Authentication:** Secure login and registration system with password hashing.
  * **Dashboard:** A central dashboard to view your details and a summary chart of your budget vs. expenses.
  * **Expense & Income Tracking:** Add, and view your daily expenses and income sources with categories.
  * **Budget Management:** Set monthly budgets for different expense categories.
  * **Task Management:** Create and view tasks with due dates and times.
  * **Reporting:** Generate monthly and custom date-range reports of your financial activity.
  * **User Profile:** View and update your personal details.
  * **Notifications:** Get reminders for upcoming tasks.

-----

## Getting Started

### Prerequisites

  * **Visual Studio:** You will need Visual Studio to open and build the project.
  * **SQL Server:** An instance of SQL Server is required to set up the database. The connection string in the project points to `THARINDA\SQLEXPRESS`. You may need to change this in `DBConnection.h`.
  * **.NET Framework:** The project targets the .NET Framework 4.7.2.

### Installation

1.  **Clone the repository:**
    ```sh
    git clone https://github.com/tharinda-pamindu/personalorganizer.git
    ```
2.  **Database Setup:**
      * Open SQL Server Management Studio.
      * Create a new database named **PersonalOrganiser**.
      * Execute the SQL scripts to create the necessary tables (`users`, `income`, `expense`, `toDo`, `budget`). *Note: The SQL scripts are not included in the provided files but would be necessary for a full setup.*
3.  **Open in Visual Studio:**
      * Open the `PersonalOrganizer.sln` file in Visual Studio.
4.  **Update Connection String:**
      * Open the `DBConnection.h` file.
      * Modify the `SqlConnection` string to point to your SQL Server instance if it's different from the default.
5.  **Build and Run:**
      * Build the solution.
      * Run the application.

-----

## Usage

1.  **Register:** Create a new user account.
2.  **Login:** Sign in with your credentials.
3.  **Dashboard:** After logging in, you will be taken to the main dashboard.
4.  **Add Expense/Income:** Use the respective buttons to add new financial entries.
5.  **Set Budget:** Go to the budget section to set your monthly spending limits for various categories.
6.  **Manage Tasks:** Add new tasks to your to-do list and view them.
7.  **Generate Reports:** Use the reporting feature to get insights into your finances.

-----

## Built With

  * **C++/CLI:** The core language used for the project.
  * **Windows Forms:** For the graphical user interface.
  * **SQL Server:** As the database for storing user data.
  * **AES Encryption:** For hashing user passwords.

-----

## Author

  * **Tharinda Pamindu** - [your-username](https://github.com/your-username)
