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
	/// Summary for ShowTask
	/// </summary>
	public ref class ShowTask : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		ShowTask(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;
			this->CenterToScreen();

			//LoadData();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ShowTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::ListView^ listTask;
	private: System::Windows::Forms::ColumnHeader^ columnTask;
	private: System::Windows::Forms::ColumnHeader^ columnDate;
	private: System::Windows::Forms::ColumnHeader^ columnTime;
	private: System::Windows::Forms::Button^ btnOk;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ShowTask::typeid));
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->listTask = (gcnew System::Windows::Forms::ListView());
			this->columnTask = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnDate = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnTime = (gcnew System::Windows::Forms::ColumnHeader());
			this->btnOk = (gcnew System::Windows::Forms::Button());
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
			this->lblHead->Size = System::Drawing::Size(711, 62);
			this->lblHead->TabIndex = 0;
			this->lblHead->Text = L"Task";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// listTask
			// 
			this->listTask->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->columnTask, this->columnDate,
					this->columnTime
			});
			this->listTask->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->listTask->GridLines = true;
			this->listTask->HideSelection = false;
			this->listTask->Location = System::Drawing::Point(11, 65);
			this->listTask->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listTask->Name = L"listTask";
			this->listTask->Size = System::Drawing::Size(690, 312);
			this->listTask->TabIndex = 1;
			this->listTask->UseCompatibleStateImageBehavior = false;
			this->listTask->View = System::Windows::Forms::View::Details;
			// 
			// columnTask
			// 
			this->columnTask->Text = L"Task";
			this->columnTask->Width = 250;
			// 
			// columnDate
			// 
			this->columnDate->Text = L"Date";
			this->columnDate->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->columnDate->Width = 148;
			// 
			// columnTime
			// 
			this->columnTime->Text = L"Time";
			this->columnTime->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->columnTime->Width = 110;
			// 
			// btnOk
			// 
			this->btnOk->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnOk->Location = System::Drawing::Point(561, 389);
			this->btnOk->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(140, 46);
			this->btnOk->TabIndex = 2;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &ShowTask::btnOk_Click);
			// 
			// ShowTask
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(711, 449);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->listTask);
			this->Controls->Add(this->lblHead);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"ShowTask";
			this->Text = L"ShowTask";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: String^ query = "SELECT [task], [date], [time] FROM [dbo].[toDo] WHERE userID = @UserID AND date >= @Date";
	public: void Today() {
		query = "SELECT [task], [date], [time] FROM [dbo].[toDo] WHERE userID = @UserID AND date = @Date";
	}
	public: void LoadData() {
		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

		command->Parameters->AddWithValue("@UserID", user->Id);
		command->Parameters->AddWithValue("@Date", DateTime::Now.ToString("yyyy-MM-dd"));

		SqlDataReader^ reader = command->ExecuteReader();

		try {
			while (reader->Read()) {
				ListViewItem^ item = gcnew ListViewItem(reader->GetString(0));
				DateTime^ time = reader->GetDateTime(1) + reader->GetTimeSpan(2);
				/*item->SubItems->Add(reader->GetDateTime(1).ToString("yyyy-MM-dd"));
				item->SubItems->Add(reader->GetTimeSpan(2).ToString());*/
				item->SubItems->Add(time->ToString("yyyy-MM-dd"));
				item->SubItems->Add(time->ToString("hh:mm tt"));
				listTask->Items->Add(item);
			}
		}
		catch (Exception^ e) { throw e; }
		finally {
			reader->Close();
			connection->CloseConnection();
		}
	}
};
}
