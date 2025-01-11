#pragma once
#include"DBConnection.h"
#include"User.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MonthlyReport
	/// </summary>
	public ref class MonthlyReport : public System::Windows::Forms::Form
	{
	private: 
		User^ user;
	public:
		MonthlyReport(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->CenterToScreen();

			this->user = user;

			txtTotalIncome->Text = "0";
			txtTotalExpense->Text = "0";
			txtDeficit->Text = "0";

			SetIncomes();
			SetExpense();
			SetTotal();

			this->lblMsg->Text = "This contains data from " + user->NextDate.AddMonths(-1).ToString("yyyy-MM-dd") + " onwards.";
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MonthlyReport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnOk;
	private: System::Windows::Forms::GroupBox^ grpIncome;
	private: System::Windows::Forms::GroupBox^ grpExpense;
	private: System::Windows::Forms::FlowLayoutPanel^ grpTotalIncomeAndExpense;
	private: System::Windows::Forms::Label^ lblTotalIncome;
	private: System::Windows::Forms::Label^ lblTotalExpense;
	private: System::Windows::Forms::Label^ lblDeficit;
	private: System::Windows::Forms::GroupBox^ grpTotal;
	private: System::Windows::Forms::Label^ txtTotalIncome;
	private: System::Windows::Forms::Label^ txtTotalExpense;
	private: System::Windows::Forms::Label^ txtDeficit;
	private: System::Windows::Forms::ListView^ expenseList;
	private: System::Windows::Forms::ColumnHeader^ expenseListTitle;
	private: System::Windows::Forms::ColumnHeader^ expenseListAmount;
	private: System::Windows::Forms::ListView^ incomeList;
	private: System::Windows::Forms::ColumnHeader^ incomeListTitle;
	private: System::Windows::Forms::ColumnHeader^ incomeListAmount;
	private: System::Windows::Forms::Label^ lblMsg;








	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MonthlyReport::typeid));
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->grpIncome = (gcnew System::Windows::Forms::GroupBox());
			this->incomeList = (gcnew System::Windows::Forms::ListView());
			this->incomeListTitle = (gcnew System::Windows::Forms::ColumnHeader());
			this->incomeListAmount = (gcnew System::Windows::Forms::ColumnHeader());
			this->grpExpense = (gcnew System::Windows::Forms::GroupBox());
			this->expenseList = (gcnew System::Windows::Forms::ListView());
			this->expenseListTitle = (gcnew System::Windows::Forms::ColumnHeader());
			this->expenseListAmount = (gcnew System::Windows::Forms::ColumnHeader());
			this->grpTotalIncomeAndExpense = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->lblTotalIncome = (gcnew System::Windows::Forms::Label());
			this->lblTotalExpense = (gcnew System::Windows::Forms::Label());
			this->lblDeficit = (gcnew System::Windows::Forms::Label());
			this->txtTotalIncome = (gcnew System::Windows::Forms::Label());
			this->txtTotalExpense = (gcnew System::Windows::Forms::Label());
			this->txtDeficit = (gcnew System::Windows::Forms::Label());
			this->grpTotal = (gcnew System::Windows::Forms::GroupBox());
			this->lblMsg = (gcnew System::Windows::Forms::Label());
			this->grpIncome->SuspendLayout();
			this->grpExpense->SuspendLayout();
			this->grpTotalIncomeAndExpense->SuspendLayout();
			this->grpTotal->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOk
			// 
			this->btnOk->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOk->Location = System::Drawing::Point(169, 729);
			this->btnOk->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(175, 45);
			this->btnOk->TabIndex = 0;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &MonthlyReport::btnOk_Click);
			// 
			// grpIncome
			// 
			this->grpIncome->Controls->Add(this->incomeList);
			this->grpIncome->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpIncome->Location = System::Drawing::Point(49, 343);
			this->grpIncome->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpIncome->Name = L"grpIncome";
			this->grpIncome->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpIncome->Size = System::Drawing::Size(418, 148);
			this->grpIncome->TabIndex = 11;
			this->grpIncome->TabStop = false;
			this->grpIncome->Text = L"INCOME";
			// 
			// incomeList
			// 
			this->incomeList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->incomeListTitle,
					this->incomeListAmount
			});
			this->incomeList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->incomeList->HideSelection = false;
			this->incomeList->Location = System::Drawing::Point(3, 24);
			this->incomeList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->incomeList->Name = L"incomeList";
			this->incomeList->Size = System::Drawing::Size(412, 122);
			this->incomeList->TabIndex = 0;
			this->incomeList->UseCompatibleStateImageBehavior = false;
			this->incomeList->View = System::Windows::Forms::View::Details;
			// 
			// incomeListTitle
			// 
			this->incomeListTitle->Text = L"Title";
			this->incomeListTitle->Width = 200;
			// 
			// incomeListAmount
			// 
			this->incomeListAmount->Text = L"Amount";
			this->incomeListAmount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->incomeListAmount->Width = 100;
			// 
			// grpExpense
			// 
			this->grpExpense->Controls->Add(this->expenseList);
			this->grpExpense->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpExpense->Location = System::Drawing::Point(49, 48);
			this->grpExpense->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpExpense->Name = L"grpExpense";
			this->grpExpense->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpExpense->Size = System::Drawing::Size(418, 269);
			this->grpExpense->TabIndex = 12;
			this->grpExpense->TabStop = false;
			this->grpExpense->Text = L"EXPENSE";
			// 
			// expenseList
			// 
			this->expenseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->expenseListTitle,
					this->expenseListAmount
			});
			this->expenseList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->expenseList->HideSelection = false;
			this->expenseList->Location = System::Drawing::Point(3, 24);
			this->expenseList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->expenseList->Name = L"expenseList";
			this->expenseList->Size = System::Drawing::Size(412, 243);
			this->expenseList->TabIndex = 1;
			this->expenseList->UseCompatibleStateImageBehavior = false;
			this->expenseList->View = System::Windows::Forms::View::Details;
			// 
			// expenseListTitle
			// 
			this->expenseListTitle->Text = L"Title";
			this->expenseListTitle->Width = 200;
			// 
			// expenseListAmount
			// 
			this->expenseListAmount->Text = L"Amount";
			this->expenseListAmount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->expenseListAmount->Width = 100;
			// 
			// grpTotalIncomeAndExpense
			// 
			this->grpTotalIncomeAndExpense->Controls->Add(this->lblTotalIncome);
			this->grpTotalIncomeAndExpense->Controls->Add(this->lblTotalExpense);
			this->grpTotalIncomeAndExpense->Controls->Add(this->lblDeficit);
			this->grpTotalIncomeAndExpense->Controls->Add(this->txtTotalIncome);
			this->grpTotalIncomeAndExpense->Controls->Add(this->txtTotalExpense);
			this->grpTotalIncomeAndExpense->Controls->Add(this->txtDeficit);
			this->grpTotalIncomeAndExpense->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grpTotalIncomeAndExpense->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->grpTotalIncomeAndExpense->Location = System::Drawing::Point(3, 24);
			this->grpTotalIncomeAndExpense->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpTotalIncomeAndExpense->Name = L"grpTotalIncomeAndExpense";
			this->grpTotalIncomeAndExpense->Size = System::Drawing::Size(412, 109);
			this->grpTotalIncomeAndExpense->TabIndex = 13;
			// 
			// lblTotalIncome
			// 
			this->lblTotalIncome->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalIncome->Location = System::Drawing::Point(3, 0);
			this->lblTotalIncome->Name = L"lblTotalIncome";
			this->lblTotalIncome->Size = System::Drawing::Size(143, 29);
			this->lblTotalIncome->TabIndex = 1;
			this->lblTotalIncome->Text = L"Total Income";
			this->lblTotalIncome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblTotalExpense
			// 
			this->lblTotalExpense->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTotalExpense->Location = System::Drawing::Point(3, 29);
			this->lblTotalExpense->Name = L"lblTotalExpense";
			this->lblTotalExpense->Size = System::Drawing::Size(132, 29);
			this->lblTotalExpense->TabIndex = 2;
			this->lblTotalExpense->Text = L"Total Expense";
			this->lblTotalExpense->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblDeficit
			// 
			this->lblDeficit->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblDeficit->Location = System::Drawing::Point(3, 58);
			this->lblDeficit->Name = L"lblDeficit";
			this->lblDeficit->Size = System::Drawing::Size(132, 29);
			this->lblDeficit->TabIndex = 3;
			this->lblDeficit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtTotalIncome
			// 
			this->txtTotalIncome->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTotalIncome->Location = System::Drawing::Point(152, 0);
			this->txtTotalIncome->Name = L"txtTotalIncome";
			this->txtTotalIncome->Size = System::Drawing::Size(155, 29);
			this->txtTotalIncome->TabIndex = 5;
			this->txtTotalIncome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtTotalExpense
			// 
			this->txtTotalExpense->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTotalExpense->Location = System::Drawing::Point(152, 29);
			this->txtTotalExpense->Name = L"txtTotalExpense";
			this->txtTotalExpense->Size = System::Drawing::Size(155, 29);
			this->txtTotalExpense->TabIndex = 6;
			this->txtTotalExpense->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtDeficit
			// 
			this->txtDeficit->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDeficit->Location = System::Drawing::Point(152, 58);
			this->txtDeficit->Name = L"txtDeficit";
			this->txtDeficit->Size = System::Drawing::Size(155, 29);
			this->txtDeficit->TabIndex = 7;
			this->txtDeficit->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// grpTotal
			// 
			this->grpTotal->Controls->Add(this->grpTotalIncomeAndExpense);
			this->grpTotal->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpTotal->Location = System::Drawing::Point(49, 516);
			this->grpTotal->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpTotal->Name = L"grpTotal";
			this->grpTotal->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpTotal->Size = System::Drawing::Size(418, 135);
			this->grpTotal->TabIndex = 14;
			this->grpTotal->TabStop = false;
			this->grpTotal->Text = L"TOTAL";
			// 
			// lblMsg
			// 
			this->lblMsg->BackColor = System::Drawing::Color::Transparent;
			this->lblMsg->Font = (gcnew System::Drawing::Font(L"Sitka Text", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblMsg->ForeColor = System::Drawing::Color::Red;
			this->lblMsg->Location = System::Drawing::Point(49, 668);
			this->lblMsg->Name = L"lblMsg";
			this->lblMsg->Size = System::Drawing::Size(418, 47);
			this->lblMsg->TabIndex = 15;
			this->lblMsg->Text = L"msg";
			this->lblMsg->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MonthlyReport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(521, 809);
			this->Controls->Add(this->lblMsg);
			this->Controls->Add(this->grpTotal);
			this->Controls->Add(this->grpExpense);
			this->Controls->Add(this->grpIncome);
			this->Controls->Add(this->btnOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MonthlyReport";
			this->Text = L"Manage Me";
			this->grpIncome->ResumeLayout(false);
			this->grpExpense->ResumeLayout(false);
			this->grpTotalIncomeAndExpense->ResumeLayout(false);
			this->grpTotal->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: void SetIncomes() {

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ questionQuery = "IF EXISTS (SELECT category, SUM(amount) AS total FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decision = gcnew SqlCommand(questionQuery, connection->GetConnection());

		decision->Parameters->AddWithValue("@UserID", user->Id);
		decision->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
		decision->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

		SqlDataReader^ answer = decision->ExecuteReader();

		if (answer->Read()) {
			if (answer->GetString(0) == "Exists") {
				answer->Close();

				//Check availability
				String^ query = "SELECT category, SUM(amount) AS total FROM income WHERE userID = @userID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category ORDER BY category ASC";
				SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

				command->Parameters->AddWithValue("@userID", user->Id);
				command->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
				command->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

				SqlDataReader^ reader = command->ExecuteReader();

				try {
					while (reader->Read()) {

						ListViewItem^ item = gcnew ListViewItem(reader->GetString(0));
						item->SubItems->Add(reader->GetDecimal(1).ToString());
						incomeList->Items->Add(item);

					}
				}
				catch (Exception^) {
					MessageBox::Show("Error", "Manage Me | Income", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				finally {
					reader->Close();
					connection->CloseConnection();
				}

			}
			else {
				answer->Close();
				connection->CloseConnection();
			}
		}


	}
	private: void SetExpense(){

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ questionQuery = "IF EXISTS (SELECT * FROM expense WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decision = gcnew SqlCommand(questionQuery, connection->GetConnection());

		decision->Parameters->AddWithValue("@UserID", user->Id);
		decision->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
		decision->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

		SqlDataReader^ answer = decision->ExecuteReader();

		if (answer->Read()) {

			if (answer->GetString(0) == "Exists") {
				answer->Close();


				String^ query = "SELECT category, SUM(amount) AS total FROM expense WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category ORDER BY category ASC";
				SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

				command->Parameters->AddWithValue("@UserID", user->Id);
				command->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
				command->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

				SqlDataReader^ reader = command->ExecuteReader();

				try {

					while (reader->Read()) {

						String^ category = reader->GetString(0);

						ListViewItem^ item = gcnew ListViewItem(category);
						item->SubItems->Add(reader->GetDecimal(1).ToString());
						expenseList->Items->Add(item);

					}
				}
				catch (Exception^) {
					MessageBox::Show("Error", "Menage Me | Expense", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				finally {
					reader->Close();
					connection->CloseConnection();
				}

			}
			else {
				answer->Close();
				connection->CloseConnection();
			}

		}

	}
	private: void SetTotal() {

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		Decimal income, expense;

		////////
		String^ questionQueryForIncome = "IF EXISTS (SELECT * FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decisionForIncome = gcnew SqlCommand(questionQueryForIncome, connection->GetConnection());

		decisionForIncome->Parameters->AddWithValue("@UserID", user->Id);
		decisionForIncome->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
		decisionForIncome->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

		SqlDataReader^ answerForIncome = decisionForIncome->ExecuteReader();

		if (answerForIncome->Read()) {
			if (answerForIncome->GetString(0) == "Exists") {
				answerForIncome->Close();

				String^ queryIncome = "SELECT SUM(amount) FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo";
				SqlCommand^ commandIncome = gcnew SqlCommand(queryIncome, connection->GetConnection());

				commandIncome->Parameters->AddWithValue("@UserID", user->Id);
				commandIncome->Parameters->AddWithValue("@DateFrom", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
				commandIncome->Parameters->AddWithValue("@DateTo", DateTime::Now.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerIncome = commandIncome->ExecuteReader();

				try {
					if (readerIncome->Read()) {
						income = readerIncome->GetDecimal(0);
						txtTotalIncome->Text = income.ToString();
					}
				}
				catch (Exception^ e) {
					throw e;
				}
				finally {
					readerIncome->Close();
					answerForIncome->Close();
				}

			}
			else {
				income = 0;
				answerForIncome->Close();
			}
		}
		/////////

		/////////
		String^ questionQueryForExpense = "IF EXISTS (SELECT * FROM expense WHERE userID = @UserID AND date BETWEEN @FirstDate AND @LastDate) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decisionForExpense = gcnew SqlCommand(questionQueryForExpense, connection->GetConnection());

		decisionForExpense->Parameters->AddWithValue("@UserID", user->Id);
		decisionForExpense->Parameters->AddWithValue("@FirstDate", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
		decisionForExpense->Parameters->AddWithValue("@LastDate", DateTime::Now.ToString("yyyy-MM-dd"));

		SqlDataReader^ answerForExpense = decisionForExpense->ExecuteReader();

		if (answerForExpense->Read()) {

			if (answerForExpense->GetString(0) == "Exists") {
				answerForExpense->Close();

				String^ queryExpense = "SELECT SUM(amount) FROM expense WHERE userID = @UserID AND date BETWEEN @FirstDate AND @LastDate";
				SqlCommand^ commandExpense = gcnew SqlCommand(queryExpense, connection->GetConnection());


				commandExpense->Parameters->AddWithValue("@UserID", user->Id);
				commandExpense->Parameters->AddWithValue("@FirstDate", DateTime::Now.AddMonths(-1).ToString("yyyy-MM-dd"));
				commandExpense->Parameters->AddWithValue("@LastDate", DateTime::Now.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerExpense = commandExpense->ExecuteReader();

				try {
					if (readerExpense->Read()) {
						expense = readerExpense->GetDecimal(0);
						txtTotalExpense->Text = expense.ToString();
					}
				}
				catch (Exception^ e) {
					throw e;
				}
				finally {
					readerExpense->Close();
					connection->CloseConnection();
				}

			}
			else {
				expense = 0;
				answerForExpense->Close();
			}

		}
		////////


		if (income > expense) {
			lblDeficit->Text = "Profit";
			txtDeficit->Text = (Decimal::ToDouble(income) - Decimal::ToDouble(expense)).ToString() + ".00";
		}
		else if(income < expense){
			lblDeficit->Text = "Deficit";
			txtDeficit->Text = (Decimal::ToDouble(expense) - Decimal::ToDouble(income)).ToString() + ".00";
		}
		else {
			lblDeficit->Text = "Total";
			txtDeficit->Text = "0";
		}

	}
};
}
