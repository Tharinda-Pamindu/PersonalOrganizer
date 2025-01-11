#pragma once
#include"IncomeCategory.h"
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
	/// Summary for IncomeForm
	/// </summary>
	public ref class IncomeForm : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		IncomeForm(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			this->user = user;

			SetItemToCategory();

			DailyUpdate();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~IncomeForm()
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
	private: System::Windows::Forms::TextBox^ txtAmount;
	private: System::Windows::Forms::ComboBox^ categoryMenu;
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::GroupBox^ lblCategory;
	private: System::Windows::Forms::GroupBox^ lblAmount;
	private: System::Windows::Forms::GroupBox^ lblDate;
	private: System::Windows::Forms::GroupBox^ lblDescription;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IncomeForm::typeid));
			this->expenseGrp = (gcnew System::Windows::Forms::GroupBox());
			this->lblDate = (gcnew System::Windows::Forms::GroupBox());
			this->datePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblDescription = (gcnew System::Windows::Forms::GroupBox());
			this->textDescription = (gcnew System::Windows::Forms::TextBox());
			this->lblAmount = (gcnew System::Windows::Forms::GroupBox());
			this->txtAmount = (gcnew System::Windows::Forms::TextBox());
			this->lblCategory = (gcnew System::Windows::Forms::GroupBox());
			this->categoryMenu = (gcnew System::Windows::Forms::ComboBox());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->expenseGrp->SuspendLayout();
			this->lblDate->SuspendLayout();
			this->lblDescription->SuspendLayout();
			this->lblAmount->SuspendLayout();
			this->lblCategory->SuspendLayout();
			this->SuspendLayout();
			// 
			// expenseGrp
			// 
			this->expenseGrp->BackColor = System::Drawing::Color::Transparent;
			this->expenseGrp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"expenseGrp.BackgroundImage")));
			this->expenseGrp->Controls->Add(this->lblDate);
			this->expenseGrp->Controls->Add(this->lblDescription);
			this->expenseGrp->Controls->Add(this->lblAmount);
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
			this->expenseGrp->Size = System::Drawing::Size(463, 611);
			this->expenseGrp->TabIndex = 2;
			this->expenseGrp->TabStop = false;
			// 
			// lblDate
			// 
			this->lblDate->Controls->Add(this->datePicker);
			this->lblDate->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblDate->Location = System::Drawing::Point(52, 272);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(352, 74);
			this->lblDate->TabIndex = 25;
			this->lblDate->TabStop = false;
			this->lblDate->Text = L"Date";
			// 
			// datePicker
			// 
			this->datePicker->Dock = System::Windows::Forms::DockStyle::Fill;
			this->datePicker->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->datePicker->Location = System::Drawing::Point(3, 29);
			this->datePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePicker->Name = L"datePicker";
			this->datePicker->Size = System::Drawing::Size(346, 33);
			this->datePicker->TabIndex = 19;
			this->datePicker->Value = System::DateTime(2024, 10, 22, 0, 0, 0, 0);
			// 
			// lblDescription
			// 
			this->lblDescription->Controls->Add(this->textDescription);
			this->lblDescription->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblDescription->Location = System::Drawing::Point(52, 369);
			this->lblDescription->Name = L"lblDescription";
			this->lblDescription->Size = System::Drawing::Size(352, 124);
			this->lblDescription->TabIndex = 24;
			this->lblDescription->TabStop = false;
			this->lblDescription->Text = L"Description";
			// 
			// textDescription
			// 
			this->textDescription->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textDescription->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->textDescription->Location = System::Drawing::Point(3, 29);
			this->textDescription->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textDescription->Multiline = true;
			this->textDescription->Name = L"textDescription";
			this->textDescription->Size = System::Drawing::Size(346, 92);
			this->textDescription->TabIndex = 17;
			// 
			// lblAmount
			// 
			this->lblAmount->Controls->Add(this->txtAmount);
			this->lblAmount->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblAmount->Location = System::Drawing::Point(52, 178);
			this->lblAmount->Name = L"lblAmount";
			this->lblAmount->Size = System::Drawing::Size(352, 74);
			this->lblAmount->TabIndex = 23;
			this->lblAmount->TabStop = false;
			this->lblAmount->Text = L"Amount";
			// 
			// txtAmount
			// 
			this->txtAmount->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtAmount->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtAmount->Location = System::Drawing::Point(3, 29);
			this->txtAmount->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtAmount->Name = L"txtAmount";
			this->txtAmount->Size = System::Drawing::Size(346, 33);
			this->txtAmount->TabIndex = 16;
			this->txtAmount->TextChanged += gcnew System::EventHandler(this, &IncomeForm::amount_Changed);
			// 
			// lblCategory
			// 
			this->lblCategory->Controls->Add(this->categoryMenu);
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblCategory->Location = System::Drawing::Point(52, 84);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Size = System::Drawing::Size(352, 74);
			this->lblCategory->TabIndex = 22;
			this->lblCategory->TabStop = false;
			this->lblCategory->Text = L"Category";
			// 
			// categoryMenu
			// 
			this->categoryMenu->Dock = System::Windows::Forms::DockStyle::Fill;
			this->categoryMenu->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->categoryMenu->FormattingEnabled = true;
			this->categoryMenu->Location = System::Drawing::Point(3, 29);
			this->categoryMenu->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->categoryMenu->Name = L"categoryMenu";
			this->categoryMenu->Size = System::Drawing::Size(346, 37);
			this->categoryMenu->TabIndex = 12;
			this->categoryMenu->Text = L"Select Category";
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnCancel->Location = System::Drawing::Point(252, 528);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(120, 40);
			this->btnCancel->TabIndex = 21;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &IncomeForm::btnCancel_Click);
			// 
			// btnAdd
			// 
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnAdd->Location = System::Drawing::Point(86, 528);
			this->btnAdd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(120, 40);
			this->btnAdd->TabIndex = 20;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &IncomeForm::btnAdd_Click);
			// 
			// lblHead
			// 
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(3, 17);
			this->lblHead->Name = L"lblHead";
			this->lblHead->Size = System::Drawing::Size(457, 51);
			this->lblHead->TabIndex = 11;
			this->lblHead->Text = L"Add Income";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// IncomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->ClientSize = System::Drawing::Size(463, 611);
			this->Controls->Add(this->expenseGrp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"IncomeForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"IncomeForm";
			this->expenseGrp->ResumeLayout(false);
			this->lblDate->ResumeLayout(false);
			this->lblDescription->ResumeLayout(false);
			this->lblDescription->PerformLayout();
			this->lblAmount->ResumeLayout(false);
			this->lblAmount->PerformLayout();
			this->lblCategory->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: void SetItemToCategory() {
		for each (IncomeCategory var in Enum::GetValues(IncomeCategory::typeid))
		{
			this->categoryMenu->Items->Add(var);
		}
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		if (user == nullptr) { this->Close(); }

		if (Int32::Parse(txtAmount->Text)>0) {

			try {
				DBConnection^ connection = DBConnection::GetInstance();
				connection->OpenConnection();

				String^ query = "INSERT INTO income(category, description, amount, date, userID) VALUES (@Category, @Description, @Amount, @Date, @UserID)";
				SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

				command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
				command->Parameters->AddWithValue("@Description", textDescription->Text);
				command->Parameters->AddWithValue("@Amount", Int32::Parse(txtAmount->Text));
				command->Parameters->AddWithValue("@Date", datePicker->Value);
				command->Parameters->AddWithValue("@UserID", user->Id);

				if (command->ExecuteNonQuery()) {
					MessageBox::Show("Added successfully", "Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
					this->Close();
				}
				else {
					throw;
				}
			}
			catch (Exception^) {
				MessageBox::Show("Income added failed", "Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		else {
			MessageBox::Show("Amount can't be 0", "Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		/*try {
			DBConnection^ connection = DBConnection::GetInstance();
			connection->OpenConnection();

			String^ query = "INSERT INTO income(category, description, amount, date, userID) VALUES (@Category, @Description, @Amount, @Date, @UserID)";
			SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

			command->Parameters->AddWithValue("@Category", categoryMenu->SelectedItem->ToString());
			command->Parameters->AddWithValue("@Description", textDescription->Text);
			command->Parameters->AddWithValue("@Amount", Int32::Parse(txtAmount->Text));
			command->Parameters->AddWithValue("@Date", datePicker->Value);
			command->Parameters->AddWithValue("@UserID", user->Id);

			if (command->ExecuteNonQuery()) {
				MessageBox::Show("Added successfully", "Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			else {
				throw;
			}
		}
		catch (Exception^) {
			MessageBox::Show("Income added failed","Menage Me", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}*/
	}
	private: System::Void amount_Changed(System::Object^ sender, System::EventArgs^ e) {
		try {
			Convert::ToInt32(txtAmount->Text);
		}
		catch (FormatException^) {
			MessageBox::Show("Invalid input! Please enter a valid amount.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->txtAmount->Text = "0";
		}
		catch (OverflowException^) {
			MessageBox::Show("The number is too large or too small.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->txtAmount->Text = "0";
		}
	}
	private: void DailyUpdate() {
		this->datePicker->Value = System::DateTime(DateTime::Now);
		this->datePicker->MaxDate = System::DateTime(DateTime::Now);
		this->datePicker->MinDate = System::DateTime(DateTime::Now.AddYears(-1));
	}
};
}
