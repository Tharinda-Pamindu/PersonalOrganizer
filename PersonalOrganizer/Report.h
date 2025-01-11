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
	/// Summary for Report
	/// </summary>
	public ref class Report : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		Report(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;

			DailyUpdate();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Report()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::GroupBox^ grpButton;
	private: System::Windows::Forms::FlowLayoutPanel^ buttonFrame;
	private: System::Windows::Forms::DateTimePicker^ datePickerFrom;
	private: System::Windows::Forms::Button^ btnGenerate;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::GroupBox^ grpExpense;
	private: System::Windows::Forms::GroupBox^ grpIncome;
	private: System::Windows::Forms::GroupBox^ grpSummary;

	//ListView 1
	private: System::Windows::Forms::ListView^ expenseList;
	private: System::Windows::Forms::ColumnHeader^ expenseCategory;
	private: System::Windows::Forms::ColumnHeader^ expenseAmount;

	//ListView 2
	private: System::Windows::Forms::ListView^ incomeList;
	private: System::Windows::Forms::ColumnHeader^ incomeCategory;
	private: System::Windows::Forms::ColumnHeader^ incomeAmount;
	private: System::Windows::Forms::DateTimePicker^ datePickerTo;
	private: System::Windows::Forms::GroupBox^ grpTo;
	private: System::Windows::Forms::GroupBox^ grpFrom;


	private: System::Windows::Forms::FlowLayoutPanel^ summaryFrame;
	private: System::Windows::Forms::Label^ lblExpense;
	private: System::Windows::Forms::Label^ lblIncome;
	private: System::Windows::Forms::Label^ lblSum;
	private: System::Windows::Forms::Label^ txtExpense;
	private: System::Windows::Forms::Label^ txtIncome;
	private: System::Windows::Forms::Label^ txtSum;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Report::typeid));
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->grpButton = (gcnew System::Windows::Forms::GroupBox());
			this->buttonFrame = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnGenerate = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->datePickerFrom = (gcnew System::Windows::Forms::DateTimePicker());
			this->grpExpense = (gcnew System::Windows::Forms::GroupBox());
			this->expenseList = (gcnew System::Windows::Forms::ListView());
			this->expenseCategory = (gcnew System::Windows::Forms::ColumnHeader());
			this->expenseAmount = (gcnew System::Windows::Forms::ColumnHeader());
			this->grpIncome = (gcnew System::Windows::Forms::GroupBox());
			this->incomeList = (gcnew System::Windows::Forms::ListView());
			this->incomeCategory = (gcnew System::Windows::Forms::ColumnHeader());
			this->incomeAmount = (gcnew System::Windows::Forms::ColumnHeader());
			this->grpSummary = (gcnew System::Windows::Forms::GroupBox());
			this->summaryFrame = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->lblExpense = (gcnew System::Windows::Forms::Label());
			this->lblIncome = (gcnew System::Windows::Forms::Label());
			this->lblSum = (gcnew System::Windows::Forms::Label());
			this->txtExpense = (gcnew System::Windows::Forms::Label());
			this->txtIncome = (gcnew System::Windows::Forms::Label());
			this->txtSum = (gcnew System::Windows::Forms::Label());
			this->datePickerTo = (gcnew System::Windows::Forms::DateTimePicker());
			this->grpTo = (gcnew System::Windows::Forms::GroupBox());
			this->grpFrom = (gcnew System::Windows::Forms::GroupBox());
			this->grpButton->SuspendLayout();
			this->buttonFrame->SuspendLayout();
			this->grpExpense->SuspendLayout();
			this->grpIncome->SuspendLayout();
			this->grpSummary->SuspendLayout();
			this->summaryFrame->SuspendLayout();
			this->grpTo->SuspendLayout();
			this->grpFrom->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblHead
			// 
			this->lblHead->BackColor = System::Drawing::Color::Transparent;
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Sitka Display", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(0, 0);
			this->lblHead->Name = L"lblHead";
			this->lblHead->Size = System::Drawing::Size(1081, 67);
			this->lblHead->TabIndex = 0;
			this->lblHead->Text = L"Report";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lblHead->Click += gcnew System::EventHandler(this, &Report::lblHead_Click);
			// 
			// grpButton
			// 
			this->grpButton->BackColor = System::Drawing::Color::Transparent;
			this->grpButton->Controls->Add(this->buttonFrame);
			this->grpButton->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpButton->Location = System::Drawing::Point(57, 549);
			this->grpButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpButton->Name = L"grpButton";
			this->grpButton->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpButton->Size = System::Drawing::Size(325, 66);
			this->grpButton->TabIndex = 1;
			this->grpButton->TabStop = false;
			this->grpButton->Text = L"Setup";
			// 
			// buttonFrame
			// 
			this->buttonFrame->Controls->Add(this->btnGenerate);
			this->buttonFrame->Controls->Add(this->btnCancel);
			this->buttonFrame->Dock = System::Windows::Forms::DockStyle::Fill;
			this->buttonFrame->Location = System::Drawing::Point(3, 28);
			this->buttonFrame->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->buttonFrame->Name = L"buttonFrame";
			this->buttonFrame->Size = System::Drawing::Size(319, 36);
			this->buttonFrame->TabIndex = 2;
			// 
			// btnGenerate
			// 
			this->btnGenerate->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnGenerate->Location = System::Drawing::Point(3, 2);
			this->btnGenerate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGenerate->Name = L"btnGenerate";
			this->btnGenerate->Size = System::Drawing::Size(153, 32);
			this->btnGenerate->TabIndex = 1;
			this->btnGenerate->Text = L"Generate";
			this->btnGenerate->UseVisualStyleBackColor = true;
			this->btnGenerate->Click += gcnew System::EventHandler(this, &Report::btnGenerate_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(162, 2);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(153, 32);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &Report::btnCancel_Click);
			// 
			// datePickerFrom
			// 
			this->datePickerFrom->Dock = System::Windows::Forms::DockStyle::Fill;
			this->datePickerFrom->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datePickerFrom->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datePickerFrom->Location = System::Drawing::Point(3, 28);
			this->datePickerFrom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePickerFrom->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->datePickerFrom->Name = L"datePickerFrom";
			this->datePickerFrom->Size = System::Drawing::Size(172, 34);
			this->datePickerFrom->TabIndex = 0;
			// 
			// grpExpense
			// 
			this->grpExpense->BackColor = System::Drawing::Color::Transparent;
			this->grpExpense->Controls->Add(this->expenseList);
			this->grpExpense->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpExpense->Location = System::Drawing::Point(50, 80);
			this->grpExpense->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpExpense->Name = L"grpExpense";
			this->grpExpense->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpExpense->Size = System::Drawing::Size(490, 333);
			this->grpExpense->TabIndex = 2;
			this->grpExpense->TabStop = false;
			this->grpExpense->Text = L"Expense";
			this->grpExpense->Enter += gcnew System::EventHandler(this, &Report::grpExpense_Enter);
			// 
			// expenseList
			// 
			this->expenseList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->expenseCategory,
					this->expenseAmount
			});
			this->expenseList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->expenseList->HideSelection = false;
			this->expenseList->Location = System::Drawing::Point(3, 28);
			this->expenseList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->expenseList->Name = L"expenseList";
			this->expenseList->Size = System::Drawing::Size(484, 303);
			this->expenseList->TabIndex = 0;
			this->expenseList->UseCompatibleStateImageBehavior = false;
			this->expenseList->View = System::Windows::Forms::View::Details;
			// 
			// expenseCategory
			// 
			this->expenseCategory->Text = L"Category";
			this->expenseCategory->Width = 219;
			// 
			// expenseAmount
			// 
			this->expenseAmount->Text = L"Amount";
			this->expenseAmount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->expenseAmount->Width = 109;
			// 
			// grpIncome
			// 
			this->grpIncome->BackColor = System::Drawing::Color::Transparent;
			this->grpIncome->Controls->Add(this->incomeList);
			this->grpIncome->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpIncome->Location = System::Drawing::Point(584, 80);
			this->grpIncome->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpIncome->Name = L"grpIncome";
			this->grpIncome->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpIncome->Size = System::Drawing::Size(444, 333);
			this->grpIncome->TabIndex = 3;
			this->grpIncome->TabStop = false;
			this->grpIncome->Text = L"Income";
			this->grpIncome->Enter += gcnew System::EventHandler(this, &Report::grpIncome_Enter);
			// 
			// incomeList
			// 
			this->incomeList->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->incomeCategory,
					this->incomeAmount
			});
			this->incomeList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->incomeList->HideSelection = false;
			this->incomeList->Location = System::Drawing::Point(3, 28);
			this->incomeList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->incomeList->Name = L"incomeList";
			this->incomeList->Size = System::Drawing::Size(438, 303);
			this->incomeList->TabIndex = 0;
			this->incomeList->UseCompatibleStateImageBehavior = false;
			this->incomeList->View = System::Windows::Forms::View::Details;
			// 
			// incomeCategory
			// 
			this->incomeCategory->Text = L"Category";
			this->incomeCategory->Width = 200;
			// 
			// incomeAmount
			// 
			this->incomeAmount->Text = L"Amount";
			this->incomeAmount->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->incomeAmount->Width = 120;
			// 
			// grpSummary
			// 
			this->grpSummary->BackColor = System::Drawing::Color::Transparent;
			this->grpSummary->Controls->Add(this->summaryFrame);
			this->grpSummary->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpSummary->Location = System::Drawing::Point(584, 457);
			this->grpSummary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpSummary->Name = L"grpSummary";
			this->grpSummary->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpSummary->Size = System::Drawing::Size(444, 133);
			this->grpSummary->TabIndex = 4;
			this->grpSummary->TabStop = false;
			this->grpSummary->Text = L"Summary";
			this->grpSummary->Enter += gcnew System::EventHandler(this, &Report::grpSummary_Enter);
			// 
			// summaryFrame
			// 
			this->summaryFrame->Controls->Add(this->lblExpense);
			this->summaryFrame->Controls->Add(this->lblIncome);
			this->summaryFrame->Controls->Add(this->lblSum);
			this->summaryFrame->Controls->Add(this->txtExpense);
			this->summaryFrame->Controls->Add(this->txtIncome);
			this->summaryFrame->Controls->Add(this->txtSum);
			this->summaryFrame->FlowDirection = System::Windows::Forms::FlowDirection::TopDown;
			this->summaryFrame->Location = System::Drawing::Point(6, 30);
			this->summaryFrame->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->summaryFrame->Name = L"summaryFrame";
			this->summaryFrame->Size = System::Drawing::Size(324, 99);
			this->summaryFrame->TabIndex = 0;
			// 
			// lblExpense
			// 
			this->lblExpense->AutoSize = true;
			this->lblExpense->Location = System::Drawing::Point(3, 0);
			this->lblExpense->Name = L"lblExpense";
			this->lblExpense->Size = System::Drawing::Size(91, 29);
			this->lblExpense->TabIndex = 0;
			this->lblExpense->Text = L"Expenses";
			this->lblExpense->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblIncome
			// 
			this->lblIncome->AutoSize = true;
			this->lblIncome->Location = System::Drawing::Point(3, 29);
			this->lblIncome->Name = L"lblIncome";
			this->lblIncome->Size = System::Drawing::Size(83, 29);
			this->lblIncome->TabIndex = 1;
			this->lblIncome->Text = L"Incomes";
			this->lblIncome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// lblSum
			// 
			this->lblSum->AutoSize = true;
			this->lblSum->Location = System::Drawing::Point(3, 58);
			this->lblSum->Name = L"lblSum";
			this->lblSum->Size = System::Drawing::Size(0, 29);
			this->lblSum->TabIndex = 2;
			this->lblSum->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtExpense
			// 
			this->txtExpense->Location = System::Drawing::Point(100, 0);
			this->txtExpense->Name = L"txtExpense";
			this->txtExpense->Size = System::Drawing::Size(212, 24);
			this->txtExpense->TabIndex = 3;
			this->txtExpense->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtIncome
			// 
			this->txtIncome->Location = System::Drawing::Point(100, 24);
			this->txtIncome->Name = L"txtIncome";
			this->txtIncome->Size = System::Drawing::Size(212, 24);
			this->txtIncome->TabIndex = 4;
			this->txtIncome->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// txtSum
			// 
			this->txtSum->Location = System::Drawing::Point(100, 48);
			this->txtSum->Name = L"txtSum";
			this->txtSum->Size = System::Drawing::Size(212, 24);
			this->txtSum->TabIndex = 5;
			this->txtSum->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// datePickerTo
			// 
			this->datePickerTo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->datePickerTo->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datePickerTo->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datePickerTo->Location = System::Drawing::Point(3, 28);
			this->datePickerTo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePickerTo->MinDate = System::DateTime(2000, 1, 1, 0, 0, 0, 0);
			this->datePickerTo->Name = L"datePickerTo";
			this->datePickerTo->Size = System::Drawing::Size(172, 34);
			this->datePickerTo->TabIndex = 5;
			// 
			// grpTo
			// 
			this->grpTo->BackColor = System::Drawing::Color::Transparent;
			this->grpTo->Controls->Add(this->datePickerTo);
			this->grpTo->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpTo->Location = System::Drawing::Point(362, 454);
			this->grpTo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpTo->Name = L"grpTo";
			this->grpTo->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpTo->Size = System::Drawing::Size(178, 66);
			this->grpTo->TabIndex = 6;
			this->grpTo->TabStop = false;
			this->grpTo->Text = L"To";
			this->grpTo->Enter += gcnew System::EventHandler(this, &Report::grpTo_Enter);
			// 
			// grpFrom
			// 
			this->grpFrom->BackColor = System::Drawing::Color::Transparent;
			this->grpFrom->Controls->Add(this->datePickerFrom);
			this->grpFrom->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->grpFrom->Location = System::Drawing::Point(50, 454);
			this->grpFrom->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpFrom->Name = L"grpFrom";
			this->grpFrom->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grpFrom->Size = System::Drawing::Size(178, 66);
			this->grpFrom->TabIndex = 7;
			this->grpFrom->TabStop = false;
			this->grpFrom->Text = L"From";
			this->grpFrom->Enter += gcnew System::EventHandler(this, &Report::grpFrom_Enter);
			// 
			// Report
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1081, 665);
			this->ControlBox = false;
			this->Controls->Add(this->grpFrom);
			this->Controls->Add(this->grpTo);
			this->Controls->Add(this->grpSummary);
			this->Controls->Add(this->grpIncome);
			this->Controls->Add(this->grpExpense);
			this->Controls->Add(this->grpButton);
			this->Controls->Add(this->lblHead);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Report";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Report";
			this->grpButton->ResumeLayout(false);
			this->buttonFrame->ResumeLayout(false);
			this->grpExpense->ResumeLayout(false);
			this->grpIncome->ResumeLayout(false);
			this->grpSummary->ResumeLayout(false);
			this->summaryFrame->ResumeLayout(false);
			this->summaryFrame->PerformLayout();
			this->grpTo->ResumeLayout(false);
			this->grpFrom->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	/*private: Decimal GetTotalExpense() {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ query = "SELECT SUM(amount) AS Total FROM expense WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo";
		SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

		command->Parameters->AddWithValue("@UserID", user->Id);
		command->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));
		command->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ reader = command->ExecuteReader();

		try {
			if (reader->Read()) {
				txtExpense->Text = reader->GetDecimal(0).ToString();
				return reader->GetDecimal(0);
			}
			else {
				return 0;
			}
		}
		catch (Exception^ e) { throw e; }
		finally {
			reader->Close();
			connection->CloseConnection();
		}

	}*/
	/*private: Decimal GetTotalIncome() {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ query = "SELECT SUM(amount) AS Total FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo";
		SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

		command->Parameters->AddWithValue("@UserID", user->Id);
		command->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));
		command->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ reader = command->ExecuteReader();

		try {
			if (reader->Read()) {
				txtIncome->Text = reader->GetDecimal(0).ToString();
				return reader->GetDecimal(0);
			}
			else {
				return 0;
			}
		}
		catch (Exception^ e) { throw e; }
		finally {
			reader->Close();
			connection->CloseConnection();
		}
	}*/
	private: System::Void btnGenerate_Click(System::Object^ sender, System::EventArgs^ e) {

		incomeList->Items->Clear();
		expenseList->Items->Clear();

		/*this->txtExpense->Text = "";
		this->txtIncome->Text = "";
		this->txtSum->Text = "";*/
		
		Nullable<DateTime> startDate = datePickerFrom->Value;
		Nullable<DateTime> endDate = datePickerTo->Value;

		if (!startDate.HasValue || !endDate.HasValue) {
			MessageBox::Show("Date empty","Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		/*DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ queryForIncome = "SELECT category, SUM(amount) AS total FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category";
		SqlCommand^ commandIncome = gcnew SqlCommand(queryForIncome, connection->GetConnection());

		commandIncome->Parameters->AddWithValue("@UserID",user->Id);
		commandIncome->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));
		commandIncome->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ readerForIncome = commandIncome->ExecuteReader();

		try {
			while (readerForIncome->Read()) {
				ListViewItem^ item = gcnew ListViewItem(readerForIncome->GetString(0));
				item->SubItems->Add(readerForIncome->GetDecimal(1).ToString());
				incomeList->Items->Add(item);
			}
		}
		catch (Exception^ e) { throw e; }
		finally {
			readerForIncome->Close();
		}

		String^ queryForExpense = "SELECT category, SUM(amount) AS total FROM expense WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category";
		SqlCommand^ commandExpense = gcnew SqlCommand(queryForExpense, connection->GetConnection());

		commandExpense->Parameters->AddWithValue("@UserID", user->Id);
		commandExpense->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));
		commandExpense->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ readerForExpense = commandExpense->ExecuteReader();

		try {
			while (readerForExpense->Read()) {
				ListViewItem^ item = gcnew ListViewItem(readerForExpense->GetString(0));
				item->SubItems->Add(readerForExpense->GetDecimal(1).ToString());
				expenseList->Items->Add(item);
			}
		}
		catch (Exception^ e) { throw e; }
		finally {
			readerForExpense->Close();
			connection->CloseConnection();
		}

		try {
			Decimal expense = GetTotalExpense();
			Decimal income = GetTotalIncome();

			if (income > expense) {
				lblSum->Text = "Profit";
				txtSum->Text = (Decimal::ToDouble(income) - Decimal::ToDouble(expense)).ToString();
			}
			else {
				lblSum->Text = "Deficit";
				txtSum->Text = (Decimal::ToDouble(expense) - Decimal::ToDouble(income)).ToString();
			}

		}
		catch (Exception^) {
			MessageBox::Show("No Incomes & expenses","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Asterisk);
		}*/

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		Decimal income, expense;

		////////
		String^ questionQueryForIncome = "IF EXISTS (SELECT SUM(amount) FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decisionForIncome = gcnew SqlCommand(questionQueryForIncome, connection->GetConnection());

		decisionForIncome->Parameters->AddWithValue("@UserID", user->Id);
		decisionForIncome->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));
		decisionForIncome->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ answerForIncome = decisionForIncome->ExecuteReader();

		if (answerForIncome->Read()) {
			if (answerForIncome->GetString(0) == "Exists") {
				answerForIncome->Close();

				String^ queryIncome = "SELECT SUM(amount) FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo";
				SqlCommand^ commandIncome = gcnew SqlCommand(queryIncome, connection->GetConnection());

				commandIncome->Parameters->AddWithValue("@UserID", user->Id);
				commandIncome->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));
				commandIncome->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerIncome = commandIncome->ExecuteReader();

				try {
					if (readerIncome->Read()) {
						income = readerIncome->GetDecimal(0);
					}
				}
				catch (Exception^) {
					income = 0;
				}
				finally {
					txtIncome->Text = income.ToString();
					readerIncome->Close();
				}

				String^ queryForIncome = "SELECT category, SUM(amount) AS total FROM income WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category";
				SqlCommand^ commandForIncome = gcnew SqlCommand(queryForIncome, connection->GetConnection());

				commandForIncome->Parameters->AddWithValue("@UserID", user->Id);
				commandForIncome->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));
				commandForIncome->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerForIncome = commandForIncome->ExecuteReader();

				try {
					while (readerForIncome->Read()) {
						ListViewItem^ item = gcnew ListViewItem(readerForIncome->GetString(0));
						item->SubItems->Add(readerForIncome->GetDecimal(1).ToString());
						incomeList->Items->Add(item);
					}
				}
				catch (Exception^ e) { throw e; }
				finally {
					readerForIncome->Close();
				}

			}
			else {
				income = 0;
				txtIncome->Text = income.ToString();
				answerForIncome->Close();
			}
		}
		/////////

		/////////
		String^ questionQueryForExpense = "IF EXISTS (SELECT SUM(amount) FROM expense WHERE userID = @UserID AND date BETWEEN @FirstDate AND @LastDate) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decisionForExpense = gcnew SqlCommand(questionQueryForExpense, connection->GetConnection());

		decisionForExpense->Parameters->AddWithValue("@UserID", user->Id);
		decisionForExpense->Parameters->AddWithValue("@FirstDate", datePickerFrom->Value.ToString("yyyy-MM-dd"));
		decisionForExpense->Parameters->AddWithValue("@LastDate", datePickerTo->Value.ToString("yyyy-MM-dd"));

		SqlDataReader^ answerForExpense = decisionForExpense->ExecuteReader();

		if (answerForExpense->Read()) {

			if (answerForExpense->GetString(0) == "Exists") {
				answerForExpense->Close();

				String^ queryExpense = "SELECT SUM(amount) FROM expense WHERE userID = @UserID AND date BETWEEN @FirstDate AND @LastDate";
				SqlCommand^ commandExpense = gcnew SqlCommand(queryExpense, connection->GetConnection());


				commandExpense->Parameters->AddWithValue("@UserID", user->Id);
				commandExpense->Parameters->AddWithValue("@FirstDate", datePickerFrom->Value.ToString("yyyy-MM-dd"));
				commandExpense->Parameters->AddWithValue("@LastDate", datePickerTo->Value.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerExpense = commandExpense->ExecuteReader();

				try {
					if (readerExpense->Read()) {
						expense = readerExpense->GetDecimal(0);
					}
				}
				catch (Exception^) {
					expense = 0;
				}
				finally {
					txtExpense->Text = expense.ToString();
					readerExpense->Close();
				}

				String^ queryForExpense = "SELECT category, SUM(amount) AS total FROM expense WHERE userID = @UserID AND date BETWEEN @DateFrom AND @DateTo GROUP BY category";
				SqlCommand^ commandForExpense = gcnew SqlCommand(queryForExpense, connection->GetConnection());

				commandForExpense->Parameters->AddWithValue("@UserID", user->Id);
				commandForExpense->Parameters->AddWithValue("@DateTo", datePickerTo->Value.ToString("yyyy-MM-dd"));
				commandForExpense->Parameters->AddWithValue("@DateFrom", datePickerFrom->Value.ToString("yyyy-MM-dd"));

				SqlDataReader^ readerForExpense = commandForExpense->ExecuteReader();

				try {
					while (readerForExpense->Read()) {
						ListViewItem^ item = gcnew ListViewItem(readerForExpense->GetString(0));
						item->SubItems->Add(readerForExpense->GetDecimal(1).ToString());
						expenseList->Items->Add(item);
					}
				}
				catch (Exception^ e) { throw e; }
				finally {
					readerForExpense->Close();
					connection->CloseConnection();
				}

			}
			else {
				expense = 0;
				txtExpense->Text = expense.ToString();
				answerForExpense->Close();
			}

		}
		////////


		if (income > expense) {
			lblSum->Text = "Profit";
			txtSum->Text = (Decimal::ToDouble(income) - Decimal::ToDouble(expense)).ToString();
		}
		else if(income < expense){
			lblSum->Text = "Deficit";
			txtSum->Text = (Decimal::ToDouble(expense) - Decimal::ToDouble(income)).ToString();
		}
		else {
			lblSum->Text = "";
			txtSum->Text = "";
		}


	}
	private: void DailyUpdate() {

		this->datePickerFrom->Value = System::DateTime(DateTime::Now.AddMonths(-1));
		this->datePickerFrom->MaxDate = System::DateTime(DateTime::Now.AddDays(-1));

		this->datePickerTo->Value = System::DateTime(DateTime::Now);
		this->datePickerTo->MaxDate = System::DateTime(DateTime::Now);

	}
private: System::Void lblHead_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grpExpense_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grpIncome_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grpFrom_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grpTo_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grpSummary_Enter(System::Object^ sender, System::EventArgs^ e) {
}
};
}
