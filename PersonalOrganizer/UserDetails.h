#pragma once
#include"User.h"
#include"DBConnection.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserDetails
	/// </summary>
	public ref class UserDetails : public System::Windows::Forms::Form
	{
	public:
		User^ user;
	public:
		UserDetails(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;

			SetUserDetails();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserDetails()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ lblName;
	private: System::Windows::Forms::GroupBox^ lblEmail;
	private: System::Windows::Forms::Label^ txtEmail;
	private: System::Windows::Forms::GroupBox^ lblPhone;
	private: System::Windows::Forms::GroupBox^ lblAddress;
	private: System::Windows::Forms::Button^ btnSave;
	private: System::Windows::Forms::TextBox^ txtName;
	private: System::Windows::Forms::TextBox^ txtPhone;
	private: System::Windows::Forms::TextBox^ txtAddress;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserDetails::typeid));
			this->lblName = (gcnew System::Windows::Forms::GroupBox());
			this->txtName = (gcnew System::Windows::Forms::TextBox());
			this->lblEmail = (gcnew System::Windows::Forms::GroupBox());
			this->txtEmail = (gcnew System::Windows::Forms::Label());
			this->lblPhone = (gcnew System::Windows::Forms::GroupBox());
			this->txtPhone = (gcnew System::Windows::Forms::TextBox());
			this->lblAddress = (gcnew System::Windows::Forms::GroupBox());
			this->txtAddress = (gcnew System::Windows::Forms::TextBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->lblName->SuspendLayout();
			this->lblEmail->SuspendLayout();
			this->lblPhone->SuspendLayout();
			this->lblAddress->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblName
			// 
			this->lblName->BackColor = System::Drawing::Color::Transparent;
			this->lblName->Controls->Add(this->txtName);
			this->lblName->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblName->Location = System::Drawing::Point(33, 35);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(314, 77);
			this->lblName->TabIndex = 0;
			this->lblName->TabStop = false;
			this->lblName->Text = L"Name";
			// 
			// txtName
			// 
			this->txtName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtName->Location = System::Drawing::Point(3, 29);
			this->txtName->Name = L"txtName";
			this->txtName->Size = System::Drawing::Size(308, 33);
			this->txtName->TabIndex = 0;
			// 
			// lblEmail
			// 
			this->lblEmail->BackColor = System::Drawing::Color::Transparent;
			this->lblEmail->Controls->Add(this->txtEmail);
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblEmail->Location = System::Drawing::Point(33, 141);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(314, 77);
			this->lblEmail->TabIndex = 1;
			this->lblEmail->TabStop = false;
			this->lblEmail->Text = L"Email";
			// 
			// txtEmail
			// 
			this->txtEmail->BackColor = System::Drawing::Color::Transparent;
			this->txtEmail->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtEmail->Location = System::Drawing::Point(3, 29);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(308, 45);
			this->txtEmail->TabIndex = 0;
			// 
			// lblPhone
			// 
			this->lblPhone->BackColor = System::Drawing::Color::Transparent;
			this->lblPhone->Controls->Add(this->txtPhone);
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblPhone->Location = System::Drawing::Point(33, 252);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(314, 77);
			this->lblPhone->TabIndex = 1;
			this->lblPhone->TabStop = false;
			this->lblPhone->Text = L"Phone Number";
			// 
			// txtPhone
			// 
			this->txtPhone->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtPhone->Location = System::Drawing::Point(3, 29);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(308, 33);
			this->txtPhone->TabIndex = 1;
			// 
			// lblAddress
			// 
			this->lblAddress->BackColor = System::Drawing::Color::Transparent;
			this->lblAddress->Controls->Add(this->txtAddress);
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblAddress->Location = System::Drawing::Point(33, 361);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(314, 77);
			this->lblAddress->TabIndex = 1;
			this->lblAddress->TabStop = false;
			this->lblAddress->Text = L"Address";
			// 
			// txtAddress
			// 
			this->txtAddress->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtAddress->Location = System::Drawing::Point(3, 29);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(308, 33);
			this->txtAddress->TabIndex = 2;
			// 
			// btnSave
			// 
			this->btnSave->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->btnSave->Location = System::Drawing::Point(117, 475);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(156, 41);
			this->btnSave->TabIndex = 2;
			this->btnSave->Text = L"SAVE";
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &UserDetails::btnSave_Click);
			// 
			// UserDetails
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(390, 540);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->lblAddress);
			this->Controls->Add(this->lblPhone);
			this->Controls->Add(this->lblEmail);
			this->Controls->Add(this->lblName);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"UserDetails";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"User Details";
			this->lblName->ResumeLayout(false);
			this->lblName->PerformLayout();
			this->lblEmail->ResumeLayout(false);
			this->lblPhone->ResumeLayout(false);
			this->lblPhone->PerformLayout();
			this->lblAddress->ResumeLayout(false);
			this->lblAddress->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void SetUserDetails() {
		txtEmail->Text = user->Email;
		txtName->Text = user->Name;
		txtPhone->Text = user->Phone;
		txtAddress->Text = user->Address;
	}
	private: System::Void btnSave_Click(System::Object^ sender, System::EventArgs^ e) {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		String^ query = "UPDATE users SET name=@Name, address=@Address, phone=@Phone WHERE email=@Email AND id=@Id";
		SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

		command->Parameters->AddWithValue("@Name",txtName->Text);
		command->Parameters->AddWithValue("@Address", txtAddress->Text);
		command->Parameters->AddWithValue("@Phone", txtPhone->Text);
		command->Parameters->AddWithValue("@Email", user->Email);
		command->Parameters->AddWithValue("@Id", user->Id);

		try {
			if (command->ExecuteNonQuery()) {
				user->Address = txtAddress->Text;
				user->Phone = txtPhone->Text;
				user->Name = txtName->Text;

				MessageBox::Show("User details updated successfully", "Manage Me", MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
		}
		catch (Exception^) {}
		finally {
			connection->CloseConnection();
		}
	}
};
}
