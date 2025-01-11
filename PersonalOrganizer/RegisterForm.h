#pragma once
#include"User.h"
#include"DBConnection.h"
#include"PasswordHash.h"
#include"ExpenseCategory.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for RegisterForm
	/// </summary>
	public ref class RegisterForm : public System::Windows::Forms::Form
	{
	public:
		RegisterForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~RegisterForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ txtConfirmPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtPhone;
	private: System::Windows::Forms::TextBox^ txtAddress;
	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::Button^ btnRegister;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::LinkLabel^ lnkToLogin;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::GroupBox^ grpSignUp;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ lblName;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::GroupBox^ lblEmail;
	private: System::Windows::Forms::GroupBox^ lblAddress;
	private: System::Windows::Forms::GroupBox^ lblPhone;
	private: System::Windows::Forms::GroupBox^ lblPassword;
	private: System::Windows::Forms::FlowLayoutPanel^ mainLogo;

	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RegisterForm::typeid));
			this->txtConfirmPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->btnRegister = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lnkToLogin = (gcnew System::Windows::Forms::LinkLabel());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->grpSignUp = (gcnew System::Windows::Forms::GroupBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lblPassword = (gcnew System::Windows::Forms::GroupBox());
			this->lblPhone = (gcnew System::Windows::Forms::GroupBox());
			this->lblAddress = (gcnew System::Windows::Forms::GroupBox());
			this->lblEmail = (gcnew System::Windows::Forms::GroupBox());
			this->lblName = (gcnew System::Windows::Forms::GroupBox());
			this->mainLogo = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->grpSignUp->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->lblPassword->SuspendLayout();
			this->lblPhone->SuspendLayout();
			this->lblAddress->SuspendLayout();
			this->lblEmail->SuspendLayout();
			this->lblName->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtConfirmPassword
			// 
			this->txtConfirmPassword->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtConfirmPassword->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtConfirmPassword->Location = System::Drawing::Point(3, 29);
			this->txtConfirmPassword->Margin = System::Windows::Forms::Padding(2);
			this->txtConfirmPassword->Name = L"txtConfirmPassword";
			this->txtConfirmPassword->PasswordChar = '*';
			this->txtConfirmPassword->Size = System::Drawing::Size(344, 33);
			this->txtConfirmPassword->TabIndex = 8;
			// 
			// txtPassword
			// 
			this->txtPassword->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtPassword->Location = System::Drawing::Point(3, 29);
			this->txtPassword->Margin = System::Windows::Forms::Padding(2);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(344, 33);
			this->txtPassword->TabIndex = 9;
			// 
			// txtPhone
			// 
			this->txtPhone->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtPhone->Location = System::Drawing::Point(3, 29);
			this->txtPhone->Margin = System::Windows::Forms::Padding(2);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(344, 33);
			this->txtPhone->TabIndex = 10;
			// 
			// txtAddress
			// 
			this->txtAddress->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtAddress->Location = System::Drawing::Point(3, 29);
			this->txtAddress->Margin = System::Windows::Forms::Padding(2);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(344, 33);
			this->txtAddress->TabIndex = 11;
			// 
			// txtEmail
			// 
			this->txtEmail->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtEmail->Location = System::Drawing::Point(3, 29);
			this->txtEmail->Margin = System::Windows::Forms::Padding(2);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(344, 33);
			this->txtEmail->TabIndex = 12;
			// 
			// btnRegister
			// 
			this->btnRegister->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnRegister->Location = System::Drawing::Point(52, 536);
			this->btnRegister->Margin = System::Windows::Forms::Padding(2);
			this->btnRegister->Name = L"btnRegister";
			this->btnRegister->Size = System::Drawing::Size(150, 40);
			this->btnRegister->TabIndex = 14;
			this->btnRegister->Text = L"Register";
			this->btnRegister->UseVisualStyleBackColor = true;
			this->btnRegister->Click += gcnew System::EventHandler(this, &RegisterForm::btnRegister_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnCancel->Location = System::Drawing::Point(238, 536);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(150, 40);
			this->btnCancel->TabIndex = 15;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &RegisterForm::btnCancel_Click);
			// 
			// lnkToLogin
			// 
			this->lnkToLogin->AutoSize = true;
			this->lnkToLogin->BackColor = System::Drawing::Color::Transparent;
			this->lnkToLogin->Font = (gcnew System::Drawing::Font(L"Sitka Display", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnkToLogin->Location = System::Drawing::Point(290, 599);
			this->lnkToLogin->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lnkToLogin->Name = L"lnkToLogin";
			this->lnkToLogin->Size = System::Drawing::Size(52, 24);
			this->lnkToLogin->TabIndex = 16;
			this->lnkToLogin->TabStop = true;
			this->lnkToLogin->Text = L"Login";
			this->lnkToLogin->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->lnkToLogin->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &RegisterForm::lnkToLogin_LinkClicked);
			// 
			// txtName
			// 
			this->txtName->BackColor = System::Drawing::SystemColors::Window;
			this->txtName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtName->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtName->Location = System::Drawing::Point(3, 29);
			this->txtName->Margin = System::Windows::Forms::Padding(2);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(344, 33);
			this->txtName->TabIndex = 17;
			// 
			// grpSignUp
			// 
			this->grpSignUp->BackColor = System::Drawing::Color::Transparent;
			this->grpSignUp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"grpSignUp.BackgroundImage")));
			this->grpSignUp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->grpSignUp->Controls->Add(this->label1);
			this->grpSignUp->Controls->Add(this->groupBox2);
			this->grpSignUp->Controls->Add(this->lnkToLogin);
			this->grpSignUp->Controls->Add(this->lblPassword);
			this->grpSignUp->Controls->Add(this->lblPhone);
			this->grpSignUp->Controls->Add(this->btnCancel);
			this->grpSignUp->Controls->Add(this->btnRegister);
			this->grpSignUp->Controls->Add(this->lblAddress);
			this->grpSignUp->Controls->Add(this->lblEmail);
			this->grpSignUp->Controls->Add(this->lblName);
			this->grpSignUp->Font = (gcnew System::Drawing::Font(L"Sitka Display", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpSignUp->Location = System::Drawing::Point(56, 23);
			this->grpSignUp->Name = L"grpSignUp";
			this->grpSignUp->Size = System::Drawing::Size(453, 696);
			this->grpSignUp->TabIndex = 18;
			this->grpSignUp->TabStop = false;
			this->grpSignUp->Text = L"Sign Up";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Display", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(94, 599);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(192, 24);
			this->label1->TabIndex = 19;
			this->label1->Text = L"Already have an account\?";
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::Color::Transparent;
			this->groupBox2->Controls->Add(this->txtConfirmPassword);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->groupBox2->Location = System::Drawing::Point(44, 442);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(350, 70);
			this->groupBox2->TabIndex = 21;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Confirm Password";
			// 
			// lblPassword
			// 
			this->lblPassword->BackColor = System::Drawing::Color::Transparent;
			this->lblPassword->Controls->Add(this->txtPassword);
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblPassword->Location = System::Drawing::Point(44, 365);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(350, 70);
			this->lblPassword->TabIndex = 22;
			this->lblPassword->TabStop = false;
			this->lblPassword->Text = L"Password";
			// 
			// lblPhone
			// 
			this->lblPhone->BackColor = System::Drawing::Color::Transparent;
			this->lblPhone->Controls->Add(this->txtPhone);
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblPhone->Location = System::Drawing::Point(44, 288);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(350, 70);
			this->lblPhone->TabIndex = 22;
			this->lblPhone->TabStop = false;
			this->lblPhone->Text = L"Phone Number";
			// 
			// lblAddress
			// 
			this->lblAddress->BackColor = System::Drawing::Color::Transparent;
			this->lblAddress->Controls->Add(this->txtAddress);
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblAddress->Location = System::Drawing::Point(44, 211);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(350, 70);
			this->lblAddress->TabIndex = 22;
			this->lblAddress->TabStop = false;
			this->lblAddress->Text = L"Address";
			// 
			// lblEmail
			// 
			this->lblEmail->BackColor = System::Drawing::Color::Transparent;
			this->lblEmail->Controls->Add(this->txtEmail);
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblEmail->Location = System::Drawing::Point(44, 134);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(350, 70);
			this->lblEmail->TabIndex = 22;
			this->lblEmail->TabStop = false;
			this->lblEmail->Text = L"Email";
			// 
			// lblName
			// 
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->Controls->Add(this->txtName);
			this->lblName->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblName->Location = System::Drawing::Point(44, 57);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(350, 70);
			this->lblName->TabIndex = 20;
			this->lblName->TabStop = false;
			this->lblName->Text = L"Name";
			// 
			// mainLogo
			// 
			this->mainLogo->BackColor = System::Drawing::Color::Transparent;
			this->mainLogo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mainLogo.BackgroundImage")));
			this->mainLogo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->mainLogo->ForeColor = System::Drawing::Color::Transparent;
			this->mainLogo->Location = System::Drawing::Point(547, 175);
			this->mainLogo->Name = L"mainLogo";
			this->mainLogo->Size = System::Drawing::Size(653, 367);
			this->mainLogo->TabIndex = 19;
			// 
			// RegisterForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::Color::DarkOrange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1257, 746);
			this->Controls->Add(this->mainLogo);
			this->Controls->Add(this->grpSignUp);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"RegisterForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Manage Me";
			this->grpSignUp->ResumeLayout(false);
			this->grpSignUp->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->lblPassword->ResumeLayout(false);
			this->lblPassword->PerformLayout();
			this->lblPhone->ResumeLayout(false);
			this->lblPhone->PerformLayout();
			this->lblAddress->ResumeLayout(false);
			this->lblAddress->PerformLayout();
			this->lblEmail->ResumeLayout(false);
			this->lblEmail->PerformLayout();
			this->lblName->ResumeLayout(false);
			this->lblName->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	public: bool shiftToLogin = false;
	private: System::Void lnkToLogin_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		shiftToLogin = true;
		this->Close();
	}
	public: User^ user = nullptr;
	private: System::Void btnRegister_Click(System::Object^ sender, System::EventArgs^ e) {

		user = gcnew User();
		int c = 0;
		String^ errorMsg;
		String^ msgTitle;

		//Password
		if (txtPassword->TextLength!=0) {

			if (txtConfirmPassword->TextLength!=0) {

				if (String::Compare(txtPassword->Text, txtConfirmPassword->Text)==0) {
					user->Password = Convert::ToBase64String(PasswordHash::Encrypt(txtPassword->Text));

					array<Byte>^ password = System::Text::Encoding::UTF8->GetBytes(user->Password);
					c++;
				}
				else {
					errorMsg = "Password doesn't match";
					msgTitle = "Password error";
				}
			}
			else {
				errorMsg = "Please Confirm password";
				msgTitle = "Password confirm";
			}
		}
		else {
			errorMsg = "Password can't be empty";
			msgTitle = "Password error";
		}

		//Phone
		if (txtPhone->TextLength < 10) {
			errorMsg = "Invalid phone number";
			msgTitle = "Phone number error";
		}
		else {
			user->Phone = txtPhone->Text;
			c++;
		}

		//Email
		if (txtEmail->TextLength != 0) {
			Regex^ emailregex = gcnew Regex("(?<user>[^@]+)@(?<host>.+)");
			Match^ m = emailregex->Match(txtEmail->Text);
			if (!m->Success) {
				errorMsg = "Invalid Email";
				msgTitle = "Email format error";
			}
			else {
				user->Email = txtEmail->Text;
				c++;
			}
		}
		else {
			errorMsg = "Email can't be empty";
			msgTitle = "Email error";
		}

		//Name
		if (txtName->TextLength == 0) {
			errorMsg = "Name can't be empty";
			msgTitle = "Name error";
		}
		else {
			user->Name = txtName->Text;
			c++; 
		}

		user->Address = txtAddress->Text;
		user->RegisteredDate = DateTime::Now;
		user->NextDate = System::DateTime(DateTime::Now.AddMonths(1));

		if (c==4) {
			
			try {
				DBConnection^ dbConnection = DBConnection::GetInstance();
				dbConnection->OpenConnection();

				String^ sqlQuery = "INSERT INTO users(name, email, address, phone, password, registered_date, nextUpdated_date) VALUES (@Name, @Email, @Address, @Phone, @Password, @RegisteredDate, @NextDate)";
				SqlCommand^ command = gcnew SqlCommand(sqlQuery, dbConnection->GetConnection());

				command->Parameters->AddWithValue("@Name",user->Name);
				command->Parameters->AddWithValue("@Email", user->Email);
				command->Parameters->AddWithValue("@Address", user->Address);
				command->Parameters->AddWithValue("@Phone", user->Phone);
				command->Parameters->AddWithValue("@Password", user->Password);
				command->Parameters->AddWithValue("@RegisteredDate",user->RegisteredDate);
				command->Parameters->AddWithValue("@NextDate", user->NextDate);

				if (command->ExecuteNonQuery()) {
					errorMsg = "New User registered successfully";
					msgTitle = "Manage Me";
					SetDefaultSetupForUser();
					this->Close();
				}

			}
			catch (Exception^ e) {
				errorMsg = e->Message;
				msgTitle = "Manage Me";
			}
		}

		shiftToLogin = true;

		MessageBox::Show(errorMsg, msgTitle, MessageBoxButtons::OK, MessageBoxIcon::Information);

	}
	private: void SetDefaultSetupForUser() {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ mainQuery = "SELECT ID FROM users WHERE email=@Email";
		SqlCommand^ command = gcnew SqlCommand(mainQuery, connection->GetConnection());

		command->Parameters->AddWithValue("@Email", user->Email);

		SqlDataReader^ reader = command->ExecuteReader();

		try{
			if (reader->Read()) {
				user->Id = reader->GetInt32(0);
			}
		}
		catch (Exception^ e) 
		{
			Console::WriteLine("Error {0}", e->Message);
		}
		finally{
			reader->Close();
		}

		String^ query = nullptr;
		SqlCommand^ insertCommand = nullptr;
		SqlTransaction^ transaction = nullptr;

		try
		{
			transaction = connection->GetConnection()->BeginTransaction();

			insertCommand = gcnew SqlCommand();
			insertCommand->Connection = connection->GetConnection();
			insertCommand->Transaction = transaction;

			query = "INSERT INTO budget(category, amount, userID) VALUES (@Category, @Amount, @UserID)";
			insertCommand->CommandText = query;

			for each (ExpenseCategory var in Enum::GetValues(ExpenseCategory::typeid))
			{
				insertCommand->Parameters->Clear();
				insertCommand->Parameters->AddWithValue("@Category", var.ToString());
				insertCommand->Parameters->AddWithValue("@Amount", 0.0);
				insertCommand->Parameters->AddWithValue("@UserID", user->Id);

				insertCommand->ExecuteNonQuery();
			}

			transaction->Commit();

		}
		catch (Exception^)
		{
			if (transaction != nullptr)
			{
				transaction->Rollback();
			}
		}
		finally
		{
			connection->CloseConnection();
		}


	}
};
}
