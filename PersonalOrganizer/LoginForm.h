#pragma once
#include"User.h"
#include"DBConnection.h"
#include"PasswordHash.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->CenterToScreen();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}









	private: System::Windows::Forms::TextBox^ txtEmail;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::LinkLabel^ lnkRegister;
	private: System::Windows::Forms::GroupBox^ lblUsername;
	private: System::Windows::Forms::GroupBox^ lblPassword;
	private: System::Windows::Forms::Label^ lblRegisterTxt;
	private: System::Windows::Forms::GroupBox^ grpSignIn;
	private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->txtEmail = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lnkRegister = (gcnew System::Windows::Forms::LinkLabel());
			this->lblUsername = (gcnew System::Windows::Forms::GroupBox());
			this->lblPassword = (gcnew System::Windows::Forms::GroupBox());
			this->lblRegisterTxt = (gcnew System::Windows::Forms::Label());
			this->grpSignIn = (gcnew System::Windows::Forms::GroupBox());
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->lblUsername->SuspendLayout();
			this->lblPassword->SuspendLayout();
			this->grpSignIn->SuspendLayout();
			this->SuspendLayout();
			// 
			// txtEmail
			// 
			this->txtEmail->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtEmail->Location = System::Drawing::Point(3, 29);
			this->txtEmail->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(394, 33);
			this->txtEmail->TabIndex = 12;
			// 
			// txtPassword
			// 
			this->txtPassword->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->txtPassword->Location = System::Drawing::Point(3, 29);
			this->txtPassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(394, 33);
			this->txtPassword->TabIndex = 13;
			// 
			// btnLogin
			// 
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnLogin->Location = System::Drawing::Point(77, 271);
			this->btnLogin->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(150, 40);
			this->btnLogin->TabIndex = 14;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnCancel->Location = System::Drawing::Point(268, 271);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(150, 40);
			this->btnCancel->TabIndex = 15;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &LoginForm::btnCancel_Click);
			// 
			// lnkRegister
			// 
			this->lnkRegister->AutoSize = true;
			this->lnkRegister->BackColor = System::Drawing::Color::Transparent;
			this->lnkRegister->Font = (gcnew System::Drawing::Font(L"Sitka Display", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lnkRegister->Location = System::Drawing::Point(315, 344);
			this->lnkRegister->Name = L"lnkRegister";
			this->lnkRegister->Size = System::Drawing::Size(71, 24);
			this->lnkRegister->TabIndex = 16;
			this->lnkRegister->TabStop = true;
			this->lnkRegister->Text = L"Register";
			this->lnkRegister->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel1_LinkClicked);
			// 
			// lblUsername
			// 
			this->lblUsername->BackColor = System::Drawing::Color::Transparent;
			this->lblUsername->Controls->Add(this->txtEmail);
			this->lblUsername->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblUsername->Location = System::Drawing::Point(48, 53);
			this->lblUsername->Name = L"lblUsername";
			this->lblUsername->Size = System::Drawing::Size(400, 70);
			this->lblUsername->TabIndex = 17;
			this->lblUsername->TabStop = false;
			this->lblUsername->Text = L"Username";
			// 
			// lblPassword
			// 
			this->lblPassword->BackColor = System::Drawing::Color::Transparent;
			this->lblPassword->Controls->Add(this->txtPassword);
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblPassword->Location = System::Drawing::Point(48, 158);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(400, 70);
			this->lblPassword->TabIndex = 18;
			this->lblPassword->TabStop = false;
			this->lblPassword->Text = L"Password";
			// 
			// lblRegisterTxt
			// 
			this->lblRegisterTxt->AutoSize = true;
			this->lblRegisterTxt->BackColor = System::Drawing::Color::Transparent;
			this->lblRegisterTxt->Font = (gcnew System::Drawing::Font(L"Sitka Display", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegisterTxt->Location = System::Drawing::Point(107, 344);
			this->lblRegisterTxt->Name = L"lblRegisterTxt";
			this->lblRegisterTxt->Size = System::Drawing::Size(192, 24);
			this->lblRegisterTxt->TabIndex = 19;
			this->lblRegisterTxt->Text = L"Doesn\'t have an account\?";
			// 
			// grpSignIn
			// 
			this->grpSignIn->BackColor = System::Drawing::Color::Transparent;
			this->grpSignIn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"grpSignIn.BackgroundImage")));
			this->grpSignIn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->grpSignIn->Controls->Add(this->lblUsername);
			this->grpSignIn->Controls->Add(this->lblRegisterTxt);
			this->grpSignIn->Controls->Add(this->btnLogin);
			this->grpSignIn->Controls->Add(this->lblPassword);
			this->grpSignIn->Controls->Add(this->btnCancel);
			this->grpSignIn->Controls->Add(this->lnkRegister);
			this->grpSignIn->Font = (gcnew System::Drawing::Font(L"Sitka Display", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpSignIn->Location = System::Drawing::Point(596, 52);
			this->grpSignIn->Name = L"grpSignIn";
			this->grpSignIn->Size = System::Drawing::Size(513, 451);
			this->grpSignIn->TabIndex = 20;
			this->grpSignIn->TabStop = false;
			this->grpSignIn->Text = L"SIGN IN";
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->BackColor = System::Drawing::Color::Transparent;
			this->flowLayoutPanel1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flowLayoutPanel1.BackgroundImage")));
			this->flowLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->flowLayoutPanel1->Location = System::Drawing::Point(57, 115);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(519, 313);
			this->flowLayoutPanel1->TabIndex = 19;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkOrange;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1168, 554);
			this->Controls->Add(this->flowLayoutPanel1);
			this->Controls->Add(this->grpSignIn);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->Text = L"User Login";
			this->lblUsername->ResumeLayout(false);
			this->lblUsername->PerformLayout();
			this->lblPassword->ResumeLayout(false);
			this->lblPassword->PerformLayout();
			this->grpSignIn->ResumeLayout(false);
			this->grpSignIn->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	public: bool shiftToRegister = false;
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
		this->shiftToRegister = true;
		this->Close();
	}
	public:User^ user = nullptr;
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		try {

			String^ sqlQuery = "SELECT * FROM users WHERE email=@email";
			SqlCommand^ command = gcnew SqlCommand(sqlQuery, connection->GetConnection());

			command->Parameters->AddWithValue("@email",txtEmail->Text);

			SqlDataReader^ reader = command->ExecuteReader();


			if (reader->Read()) {

				if (String::Compare(txtPassword->Text, PasswordHash::Decrypt(reader->GetString(5))) == 0) {
					user = gcnew User();
					user->Id = reader->GetInt32(0);
					user->Name = reader->GetString(1);
					user->Email = reader->GetString(2);
					user->Address = reader->GetString(3);
					user->Phone = reader->GetString(4);
					user->Password = reader->GetString(5);
					user->RegisteredDate = reader->GetDateTime(6);
					user->NextDate = reader->GetDateTime(7);
					this->Close();
				}
				else {
					MessageBox::Show("Password is incorrect","Sign In",MessageBoxButtons::RetryCancel, MessageBoxIcon::Error);
					txtEmail->Text = "";
					txtPassword->Text = "";
				}

			}
			else {
				MessageBox::Show("Email is incorrect","Sign In", MessageBoxButtons::RetryCancel, MessageBoxIcon::Error);
				txtEmail->Text = "";
				txtPassword->Text = "";
			}

		}
		catch (Exception^) {
			MessageBox::Show("Software issues", "Sign In", MessageBoxButtons::RetryCancel, MessageBoxIcon::Error);
		}
		finally {
			connection->CloseConnection();
		}
	}
};
}
