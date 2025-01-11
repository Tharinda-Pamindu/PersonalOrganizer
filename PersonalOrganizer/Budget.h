#pragma once
#include"User.h"
#include"ExpenseCategory.h"
#include"DBConnection.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Budget
	/// </summary>
	public ref class Budget : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		Budget(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;
			LoadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Budget()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::ComboBox^ listCategory;

	private: System::Windows::Forms::GroupBox^ lblCategory;
	private: System::Windows::Forms::GroupBox^ lblBudget;
	private: System::Windows::Forms::TextBox^ txtBudget;
	private: System::Windows::Forms::Label^ lblValue;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Budget::typeid));
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->listCategory = (gcnew System::Windows::Forms::ComboBox());
			this->lblCategory = (gcnew System::Windows::Forms::GroupBox());
			this->lblBudget = (gcnew System::Windows::Forms::GroupBox());
			this->txtBudget = (gcnew System::Windows::Forms::TextBox());
			this->lblValue = (gcnew System::Windows::Forms::Label());
			this->lblCategory->SuspendLayout();
			this->lblBudget->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblHead
			// 
			this->lblHead->BackColor = System::Drawing::Color::Transparent;
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(0, 0);
			this->lblHead->Name = L"lblHead";
			this->lblHead->Size = System::Drawing::Size(401, 74);
			this->lblHead->TabIndex = 0;
			this->lblHead->Text = L"BUDGET";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(51, 349);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 41);
			this->button1->TabIndex = 1;
			this->button1->Text = L"ADD";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Budget::btnAdd_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(227, 349);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 41);
			this->button2->TabIndex = 2;
			this->button2->Text = L"CANCEL";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Budget::btnCancel_Click);
			// 
			// listCategory
			// 
			this->listCategory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listCategory->Font = (gcnew System::Drawing::Font(L"Calisto MT", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listCategory->FormattingEnabled = true;
			this->listCategory->Location = System::Drawing::Point(3, 31);
			this->listCategory->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listCategory->Name = L"listCategory";
			this->listCategory->Size = System::Drawing::Size(288, 31);
			this->listCategory->TabIndex = 3;
			this->listCategory->SelectedValueChanged += gcnew System::EventHandler(this, &Budget::SetValueToDisplay);
			// 
			// lblCategory
			// 
			this->lblCategory->BackColor = System::Drawing::Color::Transparent;
			this->lblCategory->Controls->Add(this->listCategory);
			this->lblCategory->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCategory->Location = System::Drawing::Point(51, 93);
			this->lblCategory->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lblCategory->Name = L"lblCategory";
			this->lblCategory->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lblCategory->Size = System::Drawing::Size(294, 65);
			this->lblCategory->TabIndex = 4;
			this->lblCategory->TabStop = false;
			this->lblCategory->Text = L"Category";
			// 
			// lblBudget
			// 
			this->lblBudget->BackColor = System::Drawing::Color::Transparent;
			this->lblBudget->Controls->Add(this->txtBudget);
			this->lblBudget->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBudget->Location = System::Drawing::Point(51, 186);
			this->lblBudget->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lblBudget->Name = L"lblBudget";
			this->lblBudget->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->lblBudget->Size = System::Drawing::Size(294, 65);
			this->lblBudget->TabIndex = 5;
			this->lblBudget->TabStop = false;
			this->lblBudget->Text = L"Budget";
			// 
			// txtBudget
			// 
			this->txtBudget->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtBudget->Location = System::Drawing::Point(3, 31);
			this->txtBudget->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtBudget->Name = L"txtBudget";
			this->txtBudget->Size = System::Drawing::Size(288, 36);
			this->txtBudget->TabIndex = 0;
			this->txtBudget->TextChanged += gcnew System::EventHandler(this, &Budget::Check_Validate);
			// 
			// lblValue
			// 
			this->lblValue->BackColor = System::Drawing::Color::Transparent;
			this->lblValue->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblValue->Location = System::Drawing::Point(51, 279);
			this->lblValue->Name = L"lblValue";
			this->lblValue->Size = System::Drawing::Size(291, 41);
			this->lblValue->TabIndex = 6;
			this->lblValue->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Budget
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(401, 435);
			this->ControlBox = false;
			this->Controls->Add(this->lblValue);
			this->Controls->Add(this->lblBudget);
			this->Controls->Add(this->lblCategory);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->lblHead);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"Budget";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Budget";
			this->lblCategory->ResumeLayout(false);
			this->lblBudget->ResumeLayout(false);
			this->lblBudget->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		try {

			String^ query = "UPDATE budget SET amount=@Amount WHERE userID = @UserID AND category = @Category";
			SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

			command->Parameters->AddWithValue("@Category", listCategory->SelectedItem->ToString());
			command->Parameters->AddWithValue("@Amount", Int32::Parse(txtBudget->Text));
			command->Parameters->AddWithValue("@UserID", user->Id);

			if (command->ExecuteNonQuery()) {
				MessageBox::Show("Budget added successfully","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}

		}
		catch (Exception^ e) { Console::WriteLine("Error {0}", e->Message); }
		finally{connection->CloseConnection();}

	}
	private: void LoadData() {
		for each (ExpenseCategory var in Enum::GetValues(ExpenseCategory::typeid))
		{
			listCategory->Items->Add(var);
		}
	}
	private: System::Void Check_Validate(System::Object^ sender, System::EventArgs^ e) {
		try {
			Convert::ToInt32(txtBudget->Text);
		}
		catch (FormatException^) {
			MessageBox::Show("Invalid format","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Error);
			txtBudget->Text = "0";
		}
		catch (Exception^) {
			MessageBox::Show("Invalid value", "Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Error);
			txtBudget->Text = "0";
		}
	}
	private: System::Void SetValueToDisplay(System::Object^ sender, System::EventArgs^ e) {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ query = "SELECT amount FROM budget WHERE userID=@UserID AND category=@Category";

		SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

		command->Parameters->AddWithValue("@UserID", user->Id);
		command->Parameters->AddWithValue("@Category", listCategory->SelectedItem->ToString());
		
		SqlDataReader^ reader = command->ExecuteReader();

		try {
			if (reader->Read()) {
				lblValue->Text = reader->GetDecimal(0).ToString();
			}
			else {
				lblValue->Text = "0";
			}
		}
		catch (Exception^) {
			MessageBox::Show("No data","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
		finally {
			reader->Close();
			connection->CloseConnection();
		}
	}
};
}
