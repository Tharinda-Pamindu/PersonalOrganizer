#pragma once
#include"ExpenseCategory.h"
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
	/// Summary for ExpenseForm
	/// </summary>
	public ref class ExpenseForm : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		ExpenseForm(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->user = user;

			this->CenterToScreen();
			this->SetItemsToCategory();
			DailyUpdate();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ExpenseForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::GroupBox^ expenseGrp;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::DateTimePicker^ datePicker;
	private: System::Windows::Forms::TextBox^ textDescription;

	private: System::Windows::Forms::ComboBox^ categoryMenu;
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::GroupBox^ lblCategory;
	private: System::Windows::Forms::GroupBox^ lblDescription;
	private: System::Windows::Forms::GroupBox^ lblDate;
	private: System::Windows::Forms::GroupBox^ lblAmount;
	private: System::Windows::Forms::Label^ txtWarningMsg;
	private: System::Windows::Forms::NumericUpDown^ txtAmount;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ExpenseForm::typeid));
			this->expenseGrp = (gcnew System::Windows::Forms::GroupBox());
			this->txtWarningMsg = (gcnew System::Windows::Forms::Label());
			this->lblDate = (gcnew System::Windows::Forms::GroupBox());
			this->datePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblAmount = (gcnew System::Windows::Forms::GroupBox());
			this->txtAmount = (gcnew System::Windows::Forms::NumericUpDown());
			this->lblDescription = (gcnew System::Windows::Forms::GroupBox());
			this->textDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblCategory = (gcnew System::Windows::Forms::GroupBox());
			this->categoryMenu = (gcnew System::Windows::Forms::ComboBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->expenseGrp->SuspendLayout();
			this->lblDate->SuspendLayout();
			this->lblAmount->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtAmount))->BeginInit();
			this->lblDescription->SuspendLayout();
			this->lblCategory->SuspendLayout();
			this->SuspendLayout();
			// 
			// expenseGrp
			// 
			this->expenseGrp->BackColor = System::Drawing::Color::Chocolate;
			this->expenseGrp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expenseGrp.BackgroundImage")));
			this->expenseGrp->Controls->Add(this->txtWarningMsg);
			this->expenseGrp->Controls->Add(this->lblDate);
			this->expenseGrp->Controls->Add(this->lblAmount);
			this->expenseGrp->Controls->Add(this->lblDescription);
			this->expenseGrp->Controls->Add(this->lblCategory);
			this->expenseGrp->Controls->Add(this->btnCancel);
			this->expenseGrp->Controls->Add(this->btnAdd);
			this->expenseGrp->Controls->Add(this->lblHead);
			this->expenseGrp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->expenseGrp->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->expenseGrp->Location = System::Drawing::Point(0, 0);
			this->expenseGrp->Margin = System::Windows::Forms::Padding(4);
			this->expenseGrp->Name = L"expenseGrp";
			this->expenseGrp->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->expenseGrp->Size = System::Drawing::Size(411, 684);
			this->expenseGrp->TabIndex = 1;
			this->expenseGrp->TabStop = false;
			// 
			// txtWarningMsg
			// 
			this->txtWarningMsg->BackColor = System::Drawing::Color::Transparent;
			this->txtWarningMsg->Font = (gcnew System::Drawing::Font(L"NSimSun", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtWarningMsg->ForeColor = System::Drawing::Color::Red;
			this->txtWarningMsg->Location = System::Drawing::Point(35, 263);
			this->txtWarningMsg->Name = L"txtWarningMsg";
			this->txtWarningMsg->Size = System::Drawing::Size(337, 53);
			this->txtWarningMsg->TabIndex = 26;
			// 
			// lblDate
			// 
			this->lblDate->BackColor = System::Drawing::Color::Transparent;
			this->lblDate->Controls->Add(this->datePicker);
			this->lblDate->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblDate->Location = System::Drawing::Point(35, 326);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(337, 74);
			this->lblDate->TabIndex = 25;
			this->lblDate->TabStop = false;
			this->lblDate->Text = L"Date";
			// 
			// datePicker
			// 
			this->datePicker->Dock = System::Windows::Forms::DockStyle::Fill;
			this->datePicker->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datePicker->Location = System::Drawing::Point(3, 29);
			this->datePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePicker->Name = L"datePicker";
			this->datePicker->Size = System::Drawing::Size(331, 33);
			this->datePicker->TabIndex = 19;
			this->datePicker->Value = System::DateTime(2024, 10, 22, 0, 0, 0, 0);
			// 
			// lblAmount
			// 
			this->lblAmount->BackColor = System::Drawing::Color::Transparent;
			this->lblAmount->Controls->Add(this->txtAmount);
			this->lblAmount->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblAmount->Location = System::Drawing::Point(35, 177);
			this->lblAmount->Name = L"lblAmount";
			this->lblAmount->Size = System::Drawing::Size(337, 74);
			this->lblAmount->TabIndex = 24;
			this->lblAmount->TabStop = false;
			this->lblAmount->Text = L"Amount";
			// 
			// txtAmount
			// 
			this->txtAmount->DecimalPlaces = 2;
			this->txtAmount->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtAmount->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtAmount->Location = System::Drawing::Point(3, 29);
			this->txtAmount->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->txtAmount->Name = L"txtAmount";
			this->txtAmount->Size = System::Drawing::Size(331, 33);
			this->txtAmount->TabIndex = 27;
			//this->txtAmount->ValueChanged += gcnew System::EventHandler(this, &ExpenseForm::Amount_TextChanged);
			// 
			// lblDescription
			// 
			this->lblDescription->BackColor = System::Drawing::Color::Transparent;
			this->lblDescription->Controls->Add(this->textDescription);
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblDescription->Location = System::Drawing::Point(35, 427);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(337, 122);
			this->lblDescription->TabIndex = 23;
			this->lblDescription->TabStop = false;
			this->lblDescription->Text = L"Description";
			// 
			// textDescription
			// 
			this->textDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textDescription->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textDescription->Location = System::Drawing::Point(3, 29);
			this->textDescription->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textDescription->Multiline = true;
			this->textDescription->Name = L"textDescription";
			this->textDescription->Size = System::Drawing::Size(331, 90);
			this->textDescription->TabIndex = 17;
			// 
			// lblCategory
			// 
			this->lblCategory->BackColor = System::Drawing::Color::Transparent;
			this->lblCategory->Controls->Add(this->categoryMenu);
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblCategory->Location = System::Drawing::Point(35, 82);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(337, 74);
			this->lblCategory->TabIndex = 22;
			this->lblCategory->TabStop = false;
			this->lblCategory->Text = L"Category";
			// 
			// categoryMenu
			// 
			this->categoryMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->categoryMenu->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->categoryMenu->FormattingEnabled = true;
			this->categoryMenu->Location = System::Drawing::Point(3, 29);
			this->categoryMenu->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->categoryMenu->Name = L"categoryMenu";
			this->categoryMenu->Size = System::Drawing::Size(331, 37);
			this->categoryMenu->TabIndex = 12;
			this->categoryMenu->Text = L"Select Category";
			this->categoryMenu->SelectedValueChanged += gcnew System::EventHandler(this, &ExpenseForm::Check_Budget);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(226, 591);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(133, 45);
			this->btnCancel->TabIndex = 21;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &ExpenseForm::btnCancel_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdd->Location = System::Drawing::Point(41, 591);
			this->btnAdd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(133, 45);
			this->btnAdd->TabIndex = 20;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &ExpenseForm::btnAdd_Click);
			// 
			// lblHead
			// 
			this->lblHead->BackColor = System::Drawing::Color::Transparent;
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(3, 17);
			this->lblHead->Name = L"lblHead";
			this->lblHead->Size = System::Drawing::Size(405, 62);
			this->lblHead->TabIndex = 11;
			this->lblHead->Text = L"Add Expense";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// ExpenseForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->ClientSize = System::Drawing::Size(411, 684);
			this->Controls->Add(this->expenseGrp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ExpenseForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Manage Me";
			this->expenseGrp->ResumeLayout(false);
			this->lblDate->ResumeLayout(false);
			this->lblAmount->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->txtAmount))->EndInit();
			this->lblDescription->ResumeLayout(false);
			this->lblDescription->PerformLayout();
			this->lblCategory->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: void SetItemsToCategory() {
		for each (ExpenseCategory var in Enum::GetValues(ExpenseCategory::typeid))
		{
			this->categoryMenu->Items->Add(var);
		}
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		if (user == nullptr) {
			this->Close();
		}

		if (txtAmount->Value > 0) {

			DBConnection^ connection = DBConnection::GetInstance();
			connection->OpenConnection();

			Decimal amount;

			String^ queryForInsert = "SELECT SUM(amount) FROM expense WHERE userID = @UserID AND category = @Category AND date >= @GivenDate";
			SqlCommand^ commandForInsert = gcnew SqlCommand(queryForInsert, connection->GetConnection());

			commandForInsert->Parameters->AddWithValue("@UserID", user->Id);
			commandForInsert->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
			commandForInsert->Parameters->AddWithValue("@GivenDate", System::DateTime(user->NextDate.AddMonths(-1)));

			SqlDataReader^ readerForInsert = commandForInsert->ExecuteReader();

			try{

				if (readerForInsert->Read()) {
					amount = readerForInsert->GetDecimal(0);
				}

			}
			catch (Exception^) { amount = 0; }

			Console::WriteLine("Bugdet : " + budgetAmount + "\nTotal : " + amount.ToString() + "\nEntered Value : " + txtAmount->Value);
			Console::WriteLine("Budget : "+budgetAmount+"\nTotal Amount : "+(Decimal::ToUInt32(amount) + txtAmount->Value));
			Console::WriteLine(Decimal::ToInt32(budgetAmount) < Decimal::ToInt32(amount) + txtAmount->Value);
			
			readerForInsert->Close();

			if (Decimal::ToInt32(budgetAmount) < Decimal::ToInt32(amount) + txtAmount->Value) {

				if (MessageBox::Show("You've exceeded your " + categoryMenu->SelectedItem->ToString() + " limit","Warning", MessageBoxButtons::YesNo, MessageBoxIcon::Question, MessageBoxDefaultButton::Button1).ToString() == "Yes") {
					try {

						String^ query = "INSERT INTO expense (category, description, amount, date, userID) VALUES (@Category, @Description, @Amount, @Date, @UserID)";
						SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

						command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
						command->Parameters->AddWithValue("@Description", textDescription->Text);
						command->Parameters->AddWithValue("@Amount", txtAmount->Value);
						command->Parameters->AddWithValue("@Date", datePicker->Value);
						command->Parameters->AddWithValue("@UserID", user->Id);

						if (command->ExecuteNonQuery()) {
							MessageBox::Show("Added successfully", "Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
							this->Close();
						}

					}
					catch (Exception^) {
						MessageBox::Show("User error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
					finally {
						connection->CloseConnection();
					}
				}
				else {
					this->Close();
				}
			}
			else {
				try {

					String^ query = "INSERT INTO expense (category, description, amount, date, userID) VALUES (@Category, @Description, @Amount, @Date, @UserID)";
					SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

					command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
					command->Parameters->AddWithValue("@Description", textDescription->Text);
					command->Parameters->AddWithValue("@Amount", txtAmount->Value);
					command->Parameters->AddWithValue("@Date", datePicker->Value);
					command->Parameters->AddWithValue("@UserID", user->Id);

					if (command->ExecuteNonQuery()) {
						MessageBox::Show("Added successfully", "Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
						this->Close();
					}

				}
				catch (Exception^) {
					MessageBox::Show("User error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
				finally {
					connection->CloseConnection();
				}
			}

			/*try {

				String^ query = "INSERT INTO expense (category, description, amount, date, userID) VALUES (@Category, @Description, @Amount, @Date, @UserID)";
				SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

				command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
				command->Parameters->AddWithValue("@Description", textDescription->Text);
				command->Parameters->AddWithValue("@Amount", Int32::Parse(txtAmount->Text));
				command->Parameters->AddWithValue("@Date", datePicker->Value);
				command->Parameters->AddWithValue("@UserID", user->Id);

				if (command->ExecuteNonQuery()) {
					MessageBox::Show("Added successfully", "Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->Close();
				}

			}
			catch (Exception^) {
				MessageBox::Show("User error", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				connection->CloseConnection();
			}*/

		}
		else {
			MessageBox::Show("Amount can't be 0", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	/*private: System::Void Amount_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		try {
			Convert::ToInt32(txtAmount->Text);
		}
		catch (FormatException^) {
			MessageBox::Show("Invalid input! Please enter a valid amount.","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->txtAmount->Text = "0";
		}
		catch (OverflowException^) {
			MessageBox::Show("The number is too large or too small.", "Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->txtAmount->Text = "0";
		}
	}*/

	private: void DailyUpdate() {
		this->datePicker->MaxDate = System::DateTime(DateTime::Now);
		this->datePicker->MinDate = System::DateTime(DateTime::Now.AddYears(-1));
		this->datePicker->Value = System::DateTime(DateTime::Now);
	}
	private: Decimal budgetAmount;
	private: System::Void Check_Budget(System::Object^ sender, System::EventArgs^ e) {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		SqlCommand^ command = gcnew SqlCommand("SELECT amount FROM budget WHERE userId = @UserID AND category = @Category", connection->GetConnection());

		command->Parameters->AddWithValue("@UserID", user->Id);
		command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());

		SqlDataReader^ reader = command->ExecuteReader();

		try {
			if (reader->Read()) {
				budgetAmount = reader->GetDecimal(0);
			}
		}
		catch(Exception^){}
		finally {
			connection->CloseConnection();
			if (budgetAmount != 0)
				txtWarningMsg->Text = "You can spent only " + budgetAmount.ToString() + " for " + categoryMenu->SelectedItem->ToString() + " for this month.";
			else
				txtWarningMsg->Text = "Not set budget for " + categoryMenu->SelectedItem->ToString();
		}
	}
};
}
