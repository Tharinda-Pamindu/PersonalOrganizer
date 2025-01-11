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
	/// Summary for AddTask
	/// </summary>
	public ref class AddTask : public System::Windows::Forms::Form
	{
	private:
		User^ user = nullptr;
	public:
		AddTask(User^ user)
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
		~AddTask()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::GroupBox^ addTaskGrp;


	private: System::Windows::Forms::FlowLayoutPanel^ btnGrp;
	private: System::Windows::Forms::Button^ btnAdd;
	private: System::Windows::Forms::DateTimePicker^ datePicker;
	private: System::Windows::Forms::TextBox^ txtNote;
	private: System::Windows::Forms::TextBox^ txtTask;
	private: System::Windows::Forms::Button^ btnCancel;
	private: System::Windows::Forms::DateTimePicker^ timePicker;

	private: System::Windows::Forms::GroupBox^ lblTask;
	private: System::Windows::Forms::GroupBox^ lblNote;
	private: System::Windows::Forms::GroupBox^ lblDate;
	private: System::Windows::Forms::GroupBox^ lblTime;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AddTask::typeid));
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->addTaskGrp = (gcnew System::Windows::Forms::GroupBox());
			this->lblTime = (gcnew System::Windows::Forms::GroupBox());
			this->timePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblDate = (gcnew System::Windows::Forms::GroupBox());
			this->datePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->lblNote = (gcnew System::Windows::Forms::GroupBox());
			this->txtNote = (gcnew System::Windows::Forms::TextBox());
			this->lblTask = (gcnew System::Windows::Forms::GroupBox());
			this->txtTask = (gcnew System::Windows::Forms::TextBox());
			this->btnGrp = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnAdd = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->addTaskGrp->SuspendLayout();
			this->lblTime->SuspendLayout();
			this->lblDate->SuspendLayout();
			this->lblNote->SuspendLayout();
			this->lblTask->SuspendLayout();
			this->btnGrp->SuspendLayout();
			this->SuspendLayout();
			// 
			// lblHead
			// 
			this->lblHead->BackColor = System::Drawing::Color::Transparent;
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Perpetua Titling MT", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(3, 17);
			this->lblHead->Name = L"lblHead";
			this->lblHead->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
			this->lblHead->Size = System::Drawing::Size(461, 46);
			this->lblHead->TabIndex = 0;
			this->lblHead->Text = L"ADD TASK";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// addTaskGrp
			// 
			this->addTaskGrp->BackColor = System::Drawing::Color::Chocolate;
			this->addTaskGrp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"addTaskGrp.BackgroundImage")));
			this->addTaskGrp->Controls->Add(this->lblTime);
			this->addTaskGrp->Controls->Add(this->lblDate);
			this->addTaskGrp->Controls->Add(this->lblNote);
			this->addTaskGrp->Controls->Add(this->lblTask);
			this->addTaskGrp->Controls->Add(this->btnGrp);
			this->addTaskGrp->Controls->Add(this->lblHead);
			this->addTaskGrp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->addTaskGrp->Location = System::Drawing::Point(0, 0);
			this->addTaskGrp->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addTaskGrp->Name = L"addTaskGrp";
			this->addTaskGrp->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->addTaskGrp->Size = System::Drawing::Size(467, 496);
			this->addTaskGrp->TabIndex = 1;
			this->addTaskGrp->TabStop = false;
			// 
			// lblTime
			// 
			this->lblTime->BackColor = System::Drawing::Color::Transparent;
			this->lblTime->Controls->Add(this->timePicker);
			this->lblTime->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblTime->Location = System::Drawing::Point(272, 321);
			this->lblTime->Name = L"lblTime";
			this->lblTime->Size = System::Drawing::Size(144, 60);
			this->lblTime->TabIndex = 13;
			this->lblTime->TabStop = false;
			this->lblTime->Text = L"Time";
			// 
			// timePicker
			// 
			this->timePicker->CustomFormat = L"";
			this->timePicker->Dock = System::Windows::Forms::DockStyle::Fill;
			this->timePicker->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->timePicker->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->timePicker->Location = System::Drawing::Point(3, 29);
			this->timePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->timePicker->Name = L"timePicker";
			this->timePicker->ShowUpDown = true;
			this->timePicker->Size = System::Drawing::Size(138, 25);
			this->timePicker->TabIndex = 9;
			// 
			// lblDate
			// 
			this->lblDate->BackColor = System::Drawing::Color::Transparent;
			this->lblDate->Controls->Add(this->datePicker);
			this->lblDate->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblDate->Location = System::Drawing::Point(45, 321);
			this->lblDate->Name = L"lblDate";
			this->lblDate->Size = System::Drawing::Size(135, 60);
			this->lblDate->TabIndex = 12;
			this->lblDate->TabStop = false;
			this->lblDate->Text = L"Date";
			// 
			// datePicker
			// 
			this->datePicker->CalendarFont = (gcnew System::Drawing::Font(L"Baskerville Old Face", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datePicker->CustomFormat = L"";
			this->datePicker->Dock = System::Windows::Forms::DockStyle::Fill;
			this->datePicker->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->datePicker->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datePicker->Location = System::Drawing::Point(3, 29);
			this->datePicker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->datePicker->Name = L"datePicker";
			this->datePicker->Size = System::Drawing::Size(129, 25);
			this->datePicker->TabIndex = 4;
			// 
			// lblNote
			// 
			this->lblNote->BackColor = System::Drawing::Color::Transparent;
			this->lblNote->Controls->Add(this->txtNote);
			this->lblNote->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblNote->Location = System::Drawing::Point(45, 160);
			this->lblNote->Name = L"lblNote";
			this->lblNote->Size = System::Drawing::Size(371, 142);
			this->lblNote->TabIndex = 11;
			this->lblNote->TabStop = false;
			this->lblNote->Text = L"Note";
			// 
			// txtNote
			// 
			this->txtNote->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtNote->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtNote->Location = System::Drawing::Point(3, 29);
			this->txtNote->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtNote->Multiline = true;
			this->txtNote->Name = L"txtNote";
			this->txtNote->Size = System::Drawing::Size(365, 110);
			this->txtNote->TabIndex = 3;
			// 
			// lblTask
			// 
			this->lblTask->BackColor = System::Drawing::Color::Transparent;
			this->lblTask->Controls->Add(this->txtTask);
			this->lblTask->Font = (gcnew System::Drawing::Font(L"Sitka Display", 12, System::Drawing::FontStyle::Bold));
			this->lblTask->Location = System::Drawing::Point(45, 75);
			this->lblTask->Name = L"lblTask";
			this->lblTask->Size = System::Drawing::Size(371, 67);
			this->lblTask->TabIndex = 10;
			this->lblTask->TabStop = false;
			this->lblTask->Text = L"Task";
			// 
			// txtTask
			// 
			this->txtTask->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtTask->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTask->Location = System::Drawing::Point(3, 29);
			this->txtTask->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtTask->Name = L"txtTask";
			this->txtTask->Size = System::Drawing::Size(365, 34);
			this->txtTask->TabIndex = 7;
			// 
			// btnGrp
			// 
			this->btnGrp->BackColor = System::Drawing::Color::Transparent;
			this->btnGrp->Controls->Add(this->btnAdd);
			this->btnGrp->Controls->Add(this->btnCancel);
			this->btnGrp->Location = System::Drawing::Point(78, 422);
			this->btnGrp->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnGrp->Name = L"btnGrp";
			this->btnGrp->Size = System::Drawing::Size(300, 38);
			this->btnGrp->TabIndex = 5;
			// 
			// btnAdd
			// 
			this->btnAdd->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAdd->Location = System::Drawing::Point(3, 2);
			this->btnAdd->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAdd->Name = L"btnAdd";
			this->btnAdd->Size = System::Drawing::Size(144, 36);
			this->btnAdd->TabIndex = 0;
			this->btnAdd->Text = L"Add";
			this->btnAdd->UseVisualStyleBackColor = true;
			this->btnAdd->Click += gcnew System::EventHandler(this, &AddTask::btnAdd_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCancel->Location = System::Drawing::Point(153, 2);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(144, 36);
			this->btnCancel->TabIndex = 1;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &AddTask::btnCancel_Click);
			// 
			// AddTask
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->ClientSize = System::Drawing::Size(467, 496);
			this->Controls->Add(this->addTaskGrp);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AddTask";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"AddTask";
			this->addTaskGrp->ResumeLayout(false);
			this->lblTime->ResumeLayout(false);
			this->lblDate->ResumeLayout(false);
			this->lblNote->ResumeLayout(false);
			this->lblNote->PerformLayout();
			this->lblTask->ResumeLayout(false);
			this->lblTask->PerformLayout();
			this->btnGrp->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnCancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btnAdd_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			DBConnection^ connection = DBConnection::GetInstance();
			connection->OpenConnection();

			String^ query = "INSERT INTO toDo(task, description, date, time, userID) VALUES (@Task, @Description, @Date, @Time, @UserID)";
			SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

			command->Parameters->AddWithValue("@Task",txtTask->Text);
			command->Parameters->AddWithValue("@Description",txtNote->Text);
			command->Parameters->AddWithValue("@Date", datePicker->Value.ToString("yyyy-MM-dd"));
			command->Parameters->AddWithValue("@Time", timePicker->Value.ToString("HH:mm:ss"));
			command->Parameters->AddWithValue("@USerID", user->Id);

			if (command->ExecuteNonQuery()) {
				MessageBox::Show("Added successfully","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Information);
				this->Close();
			}
			else {
				throw;
			}

		}
		catch (Exception^) {
			MessageBox::Show("Operation failed","Error",MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	private: void DailyUpdate() {
		this->datePicker->MinDate = System::DateTime(DateTime::Now);
		this->datePicker->MaxDate = System::DateTime(DateTime::Now.AddYears(1));
	}
};
}
