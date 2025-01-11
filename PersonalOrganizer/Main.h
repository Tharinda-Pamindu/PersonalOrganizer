#pragma once
#include"User.h"
#include"ExpenseForm.h"
#include"IncomeForm.h"
#include"AddTask.h"
#include"MonthlyReport.h"
#include"Report.h"
#include"ShowTask.h"
#include"Budget.h"
#include"ExpenseCategory.h"
#include"UserDetails.h"
#include"Info.h"

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Threading;
	using namespace System::Threading::Tasks;


	/// <summary>
	/// Summary for Main
	/// </summary>
	public ref class Main : public System::Windows::Forms::Form
	{
	private:
		User^ user;
	public:
		Main(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->user = user;

			SetUserDetails();

			UpdateChart();
			MonthlyUpdate();

			this->notifyStartMsgTimer->Start();

			//StartMsg_notify();
			//notify_Warning();

			StartRealTimeTaskAsync();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ grpUserDetail;
	private: System::Windows::Forms::Label^ lblHead;
	private: System::Windows::Forms::Label^ lblPhone;
	private: System::Windows::Forms::Label^ lblEmail;
	private: System::Windows::Forms::Label^ lblName;
	private: System::Windows::Forms::Label^ lblRegisteredDate;
	private: System::Windows::Forms::Label^ lblAddress;
	private: System::Windows::Forms::FlowLayoutPanel^ incomeAndExpenseGrp;
	private: System::Windows::Forms::Button^ btnAddExpense;
	private: System::Windows::Forms::Button^ btnAddIncome;
	private: System::Windows::Forms::Button^ btnMonthlyRepo;
	private: System::Windows::Forms::FlowLayoutPanel^ toDoManagerGrp;
	private: System::Windows::Forms::Button^ btnAddTask;
	private: System::Windows::Forms::Button^ btnViewTask;
	private: System::Windows::Forms::Button^ btnToday;
	private: System::Windows::Forms::GroupBox^ grpToDo;
	private: System::Windows::Forms::Button^ btnReport;
	private: System::Windows::Forms::GroupBox^ grpExpense;
	private: System::Windows::Forms::Label^ txtEmail;
	private: System::Windows::Forms::Label^ txtDate;
	private: System::Windows::Forms::Label^ txtAddress;
	private: System::Windows::Forms::Label^ txtPhone;
	private: System::Windows::Forms::GroupBox^ grpExit;
	private: System::Windows::Forms::Button^ btnLogOut;
	private: System::Windows::Forms::Button^ btnBudget;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ summaryChrt;
	private: System::Windows::Forms::PictureBox^ imgProfile;
	private: System::Windows::Forms::PictureBox^ imgSetting;
	private: System::Windows::Forms::Label^ lblChart;
	private: System::Windows::Forms::NotifyIcon^ budgetWarning;
	private: System::Windows::Forms::PictureBox^ btnInfo;
	private: System::Windows::Forms::Timer^ notifyStartMsgTimer;





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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->grpUserDetail = (gcnew System::Windows::Forms::GroupBox());
			this->imgSetting = (gcnew System::Windows::Forms::PictureBox());
			this->imgProfile = (gcnew System::Windows::Forms::PictureBox());
			this->txtDate = (gcnew System::Windows::Forms::Label());
			this->txtAddress = (gcnew System::Windows::Forms::Label());
			this->txtPhone = (gcnew System::Windows::Forms::Label());
			this->txtEmail = (gcnew System::Windows::Forms::Label());
			this->lblRegisteredDate = (gcnew System::Windows::Forms::Label());
			this->lblAddress = (gcnew System::Windows::Forms::Label());
			this->lblPhone = (gcnew System::Windows::Forms::Label());
			this->lblEmail = (gcnew System::Windows::Forms::Label());
			this->lblName = (gcnew System::Windows::Forms::Label());
			this->lblHead = (gcnew System::Windows::Forms::Label());
			this->incomeAndExpenseGrp = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnAddExpense = (gcnew System::Windows::Forms::Button());
			this->btnAddIncome = (gcnew System::Windows::Forms::Button());
			this->btnMonthlyRepo = (gcnew System::Windows::Forms::Button());
			this->btnReport = (gcnew System::Windows::Forms::Button());
			this->btnBudget = (gcnew System::Windows::Forms::Button());
			this->toDoManagerGrp = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->btnAddTask = (gcnew System::Windows::Forms::Button());
			this->btnViewTask = (gcnew System::Windows::Forms::Button());
			this->btnToday = (gcnew System::Windows::Forms::Button());
			this->grpToDo = (gcnew System::Windows::Forms::GroupBox());
			this->grpExpense = (gcnew System::Windows::Forms::GroupBox());
			this->grpExit = (gcnew System::Windows::Forms::GroupBox());
			this->btnLogOut = (gcnew System::Windows::Forms::Button());
			this->summaryChrt = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->lblChart = (gcnew System::Windows::Forms::Label());
			this->budgetWarning = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->btnInfo = (gcnew System::Windows::Forms::PictureBox());
			this->notifyStartMsgTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->grpUserDetail->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgSetting))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgProfile))->BeginInit();
			this->incomeAndExpenseGrp->SuspendLayout();
			this->toDoManagerGrp->SuspendLayout();
			this->grpToDo->SuspendLayout();
			this->grpExpense->SuspendLayout();
			this->grpExit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->summaryChrt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnInfo))->BeginInit();
			this->SuspendLayout();
			// 
			// grpUserDetail
			// 
			this->grpUserDetail->BackColor = System::Drawing::Color::Transparent;
			this->grpUserDetail->Controls->Add(this->imgSetting);
			this->grpUserDetail->Controls->Add(this->imgProfile);
			this->grpUserDetail->Controls->Add(this->txtDate);
			this->grpUserDetail->Controls->Add(this->txtAddress);
			this->grpUserDetail->Controls->Add(this->txtPhone);
			this->grpUserDetail->Controls->Add(this->txtEmail);
			this->grpUserDetail->Controls->Add(this->lblRegisteredDate);
			this->grpUserDetail->Controls->Add(this->lblAddress);
			this->grpUserDetail->Controls->Add(this->lblPhone);
			this->grpUserDetail->Controls->Add(this->lblEmail);
			this->grpUserDetail->Controls->Add(this->lblName);
			this->grpUserDetail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpUserDetail->Location = System::Drawing::Point(47, 97);
			this->grpUserDetail->Margin = System::Windows::Forms::Padding(2);
			this->grpUserDetail->Name = L"grpUserDetail";
			this->grpUserDetail->Padding = System::Windows::Forms::Padding(2);
			this->grpUserDetail->Size = System::Drawing::Size(418, 740);
			this->grpUserDetail->TabIndex = 0;
			this->grpUserDetail->TabStop = false;
			this->grpUserDetail->Text = L"User Details";
			// 
			// imgSetting
			// 
			this->imgSetting->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgSetting.BackgroundImage")));
			this->imgSetting->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->imgSetting->Location = System::Drawing::Point(18, 671);
			this->imgSetting->Name = L"imgSetting";
			this->imgSetting->Size = System::Drawing::Size(50, 50);
			this->imgSetting->TabIndex = 10;
			this->imgSetting->TabStop = false;
			this->imgSetting->Click += gcnew System::EventHandler(this, &Main::setting_Click);
			// 
			// imgProfile
			// 
			this->imgProfile->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"imgProfile.BackgroundImage")));
			this->imgProfile->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->imgProfile->Location = System::Drawing::Point(79, 53);
			this->imgProfile->Name = L"imgProfile";
			this->imgProfile->Size = System::Drawing::Size(253, 195);
			this->imgProfile->TabIndex = 9;
			this->imgProfile->TabStop = false;
			// 
			// txtDate
			// 
			this->txtDate->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtDate->Location = System::Drawing::Point(79, 595);
			this->txtDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtDate->Name = L"txtDate";
			this->txtDate->Size = System::Drawing::Size(325, 33);
			this->txtDate->TabIndex = 8;
			// 
			// txtAddress
			// 
			this->txtAddress->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtAddress->Location = System::Drawing::Point(79, 516);
			this->txtAddress->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtAddress->Name = L"txtAddress";
			this->txtAddress->Size = System::Drawing::Size(325, 33);
			this->txtAddress->TabIndex = 7;
			// 
			// txtPhone
			// 
			this->txtPhone->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPhone->Location = System::Drawing::Point(79, 437);
			this->txtPhone->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtPhone->Name = L"txtPhone";
			this->txtPhone->Size = System::Drawing::Size(325, 33);
			this->txtPhone->TabIndex = 6;
			// 
			// txtEmail
			// 
			this->txtEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtEmail->Location = System::Drawing::Point(79, 359);
			this->txtEmail->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtEmail->Name = L"txtEmail";
			this->txtEmail->Size = System::Drawing::Size(325, 33);
			this->txtEmail->TabIndex = 5;
			// 
			// lblRegisteredDate
			// 
			this->lblRegisteredDate->AutoSize = true;
			this->lblRegisteredDate->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblRegisteredDate->Location = System::Drawing::Point(4, 556);
			this->lblRegisteredDate->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblRegisteredDate->Name = L"lblRegisteredDate";
			this->lblRegisteredDate->Size = System::Drawing::Size(183, 33);
			this->lblRegisteredDate->TabIndex = 4;
			this->lblRegisteredDate->Text = L"Registered Date :";
			// 
			// lblAddress
			// 
			this->lblAddress->AutoSize = true;
			this->lblAddress->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblAddress->Location = System::Drawing::Point(4, 477);
			this->lblAddress->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblAddress->Name = L"lblAddress";
			this->lblAddress->Size = System::Drawing::Size(106, 33);
			this->lblAddress->TabIndex = 3;
			this->lblAddress->Text = L"Address :";
			// 
			// lblPhone
			// 
			this->lblPhone->AutoSize = true;
			this->lblPhone->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPhone->Location = System::Drawing::Point(4, 398);
			this->lblPhone->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPhone->Name = L"lblPhone";
			this->lblPhone->Size = System::Drawing::Size(89, 33);
			this->lblPhone->TabIndex = 2;
			this->lblPhone->Text = L"Phone :";
			// 
			// lblEmail
			// 
			this->lblEmail->AutoSize = true;
			this->lblEmail->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblEmail->Location = System::Drawing::Point(4, 321);
			this->lblEmail->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEmail->Name = L"lblEmail";
			this->lblEmail->Size = System::Drawing::Size(83, 33);
			this->lblEmail->TabIndex = 1;
			this->lblEmail->Text = L"Email :";
			// 
			// lblName
			// 
			this->lblName->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblName->Location = System::Drawing::Point(2, 251);
			this->lblName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblName->Name = L"lblName";
			this->lblName->Size = System::Drawing::Size(414, 52);
			this->lblName->TabIndex = 0;
			this->lblName->Text = L"Name Tag";
			this->lblName->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// lblHead
			// 
			this->lblHead->BackColor = System::Drawing::Color::Transparent;
			this->lblHead->Dock = System::Windows::Forms::DockStyle::Top;
			this->lblHead->Font = (gcnew System::Drawing::Font(L"Sitka Display", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblHead->Location = System::Drawing::Point(0, 0);
			this->lblHead->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblHead->Name = L"lblHead";
			this->lblHead->Size = System::Drawing::Size(1898, 89);
			this->lblHead->TabIndex = 1;
			this->lblHead->Text = L"Dash Board";
			this->lblHead->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// incomeAndExpenseGrp
			// 
			this->incomeAndExpenseGrp->Controls->Add(this->btnAddExpense);
			this->incomeAndExpenseGrp->Controls->Add(this->btnAddIncome);
			this->incomeAndExpenseGrp->Controls->Add(this->btnMonthlyRepo);
			this->incomeAndExpenseGrp->Controls->Add(this->btnReport);
			this->incomeAndExpenseGrp->Controls->Add(this->btnBudget);
			this->incomeAndExpenseGrp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->incomeAndExpenseGrp->Location = System::Drawing::Point(2, 23);
			this->incomeAndExpenseGrp->Margin = System::Windows::Forms::Padding(2);
			this->incomeAndExpenseGrp->Name = L"incomeAndExpenseGrp";
			this->incomeAndExpenseGrp->Size = System::Drawing::Size(761, 58);
			this->incomeAndExpenseGrp->TabIndex = 2;
			// 
			// btnAddExpense
			// 
			this->btnAddExpense->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddExpense->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddExpense.Image")));
			this->btnAddExpense->Location = System::Drawing::Point(2, 2);
			this->btnAddExpense->Margin = System::Windows::Forms::Padding(2);
			this->btnAddExpense->Name = L"btnAddExpense";
			this->btnAddExpense->Size = System::Drawing::Size(168, 52);
			this->btnAddExpense->TabIndex = 0;
			this->btnAddExpense->Text = L"ADD EXPENSE";
			this->btnAddExpense->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnAddExpense->UseVisualStyleBackColor = true;
			this->btnAddExpense->Click += gcnew System::EventHandler(this, &Main::btnAddExpense_Click);
			// 
			// btnAddIncome
			// 
			this->btnAddIncome->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddIncome->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddIncome.Image")));
			this->btnAddIncome->Location = System::Drawing::Point(174, 2);
			this->btnAddIncome->Margin = System::Windows::Forms::Padding(2);
			this->btnAddIncome->Name = L"btnAddIncome";
			this->btnAddIncome->Size = System::Drawing::Size(152, 52);
			this->btnAddIncome->TabIndex = 1;
			this->btnAddIncome->Text = L"ADD INCOME";
			this->btnAddIncome->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnAddIncome->UseVisualStyleBackColor = true;
			this->btnAddIncome->Click += gcnew System::EventHandler(this, &Main::btnAddIncome_Click);
			// 
			// btnMonthlyRepo
			// 
			this->btnMonthlyRepo->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnMonthlyRepo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnMonthlyRepo.Image")));
			this->btnMonthlyRepo->Location = System::Drawing::Point(330, 2);
			this->btnMonthlyRepo->Margin = System::Windows::Forms::Padding(2);
			this->btnMonthlyRepo->Name = L"btnMonthlyRepo";
			this->btnMonthlyRepo->Size = System::Drawing::Size(148, 52);
			this->btnMonthlyRepo->TabIndex = 2;
			this->btnMonthlyRepo->Text = L"MONTHLY REPORT";
			this->btnMonthlyRepo->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnMonthlyRepo->UseVisualStyleBackColor = true;
			this->btnMonthlyRepo->Click += gcnew System::EventHandler(this, &Main::btnMonthlyRepo_Click);
			// 
			// btnReport
			// 
			this->btnReport->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnReport->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReport.Image")));
			this->btnReport->Location = System::Drawing::Point(482, 2);
			this->btnReport->Margin = System::Windows::Forms::Padding(2);
			this->btnReport->Name = L"btnReport";
			this->btnReport->Size = System::Drawing::Size(128, 52);
			this->btnReport->TabIndex = 3;
			this->btnReport->Text = L"REPORT";
			this->btnReport->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnReport->UseVisualStyleBackColor = true;
			this->btnReport->Click += gcnew System::EventHandler(this, &Main::btnReport_Click);
			// 
			// btnBudget
			// 
			this->btnBudget->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBudget->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnBudget.Image")));
			this->btnBudget->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnBudget->Location = System::Drawing::Point(614, 2);
			this->btnBudget->Margin = System::Windows::Forms::Padding(2);
			this->btnBudget->Name = L"btnBudget";
			this->btnBudget->Size = System::Drawing::Size(136, 52);
			this->btnBudget->TabIndex = 4;
			this->btnBudget->Text = L" BUDGET";
			this->btnBudget->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnBudget->UseVisualStyleBackColor = true;
			this->btnBudget->Click += gcnew System::EventHandler(this, &Main::btnBudget_Click);
			// 
			// toDoManagerGrp
			// 
			this->toDoManagerGrp->Controls->Add(this->btnAddTask);
			this->toDoManagerGrp->Controls->Add(this->btnViewTask);
			this->toDoManagerGrp->Controls->Add(this->btnToday);
			this->toDoManagerGrp->Dock = System::Windows::Forms::DockStyle::Fill;
			this->toDoManagerGrp->Location = System::Drawing::Point(2, 23);
			this->toDoManagerGrp->Margin = System::Windows::Forms::Padding(2);
			this->toDoManagerGrp->Name = L"toDoManagerGrp";
			this->toDoManagerGrp->Size = System::Drawing::Size(445, 58);
			this->toDoManagerGrp->TabIndex = 3;
			// 
			// btnAddTask
			// 
			this->btnAddTask->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAddTask->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnAddTask.Image")));
			this->btnAddTask->Location = System::Drawing::Point(2, 2);
			this->btnAddTask->Margin = System::Windows::Forms::Padding(2);
			this->btnAddTask->Name = L"btnAddTask";
			this->btnAddTask->Size = System::Drawing::Size(152, 50);
			this->btnAddTask->TabIndex = 0;
			this->btnAddTask->Text = L"ADD TASK";
			this->btnAddTask->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnAddTask->UseVisualStyleBackColor = true;
			this->btnAddTask->Click += gcnew System::EventHandler(this, &Main::btnAddTask_Click);
			// 
			// btnViewTask
			// 
			this->btnViewTask->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnViewTask->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnViewTask.Image")));
			this->btnViewTask->Location = System::Drawing::Point(158, 2);
			this->btnViewTask->Margin = System::Windows::Forms::Padding(2);
			this->btnViewTask->Name = L"btnViewTask";
			this->btnViewTask->Size = System::Drawing::Size(161, 50);
			this->btnViewTask->TabIndex = 1;
			this->btnViewTask->Text = L"VIEW TASK";
			this->btnViewTask->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnViewTask->UseVisualStyleBackColor = true;
			this->btnViewTask->Click += gcnew System::EventHandler(this, &Main::btnViewTask_Click);
			// 
			// btnToday
			// 
			this->btnToday->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnToday->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnToday.Image")));
			this->btnToday->Location = System::Drawing::Point(323, 2);
			this->btnToday->Margin = System::Windows::Forms::Padding(2);
			this->btnToday->Name = L"btnToday";
			this->btnToday->Size = System::Drawing::Size(114, 50);
			this->btnToday->TabIndex = 2;
			this->btnToday->Text = L"TODAY";
			this->btnToday->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->btnToday->UseVisualStyleBackColor = true;
			this->btnToday->Click += gcnew System::EventHandler(this, &Main::btnToday_Click);
			// 
			// grpToDo
			// 
			this->grpToDo->BackColor = System::Drawing::Color::Transparent;
			this->grpToDo->Controls->Add(this->toDoManagerGrp);
			this->grpToDo->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpToDo->Location = System::Drawing::Point(932, 880);
			this->grpToDo->Margin = System::Windows::Forms::Padding(2);
			this->grpToDo->Name = L"grpToDo";
			this->grpToDo->Padding = System::Windows::Forms::Padding(2);
			this->grpToDo->Size = System::Drawing::Size(449, 83);
			this->grpToDo->TabIndex = 4;
			this->grpToDo->TabStop = false;
			this->grpToDo->Text = L"To Do Manager";
			// 
			// grpExpense
			// 
			this->grpExpense->BackColor = System::Drawing::Color::Transparent;
			this->grpExpense->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->grpExpense->Controls->Add(this->incomeAndExpenseGrp);
			this->grpExpense->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpExpense->Location = System::Drawing::Point(60, 880);
			this->grpExpense->Margin = System::Windows::Forms::Padding(2);
			this->grpExpense->Name = L"grpExpense";
			this->grpExpense->Padding = System::Windows::Forms::Padding(2);
			this->grpExpense->Size = System::Drawing::Size(765, 83);
			this->grpExpense->TabIndex = 5;
			this->grpExpense->TabStop = false;
			this->grpExpense->Text = L"Expense and Income";
			// 
			// grpExit
			// 
			this->grpExit->BackColor = System::Drawing::Color::Transparent;
			this->grpExit->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->grpExit->Controls->Add(this->btnLogOut);
			this->grpExit->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->grpExit->Location = System::Drawing::Point(1500, 882);
			this->grpExit->Margin = System::Windows::Forms::Padding(2);
			this->grpExit->Name = L"grpExit";
			this->grpExit->Padding = System::Windows::Forms::Padding(2);
			this->grpExit->Size = System::Drawing::Size(172, 81);
			this->grpExit->TabIndex = 7;
			this->grpExit->TabStop = false;
			this->grpExit->Text = L"LogOut";
			// 
			// btnLogOut
			// 
			this->btnLogOut->Dock = System::Windows::Forms::DockStyle::Fill;
			this->btnLogOut->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnLogOut.Image")));
			this->btnLogOut->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btnLogOut->Location = System::Drawing::Point(2, 23);
			this->btnLogOut->Margin = System::Windows::Forms::Padding(8);
			this->btnLogOut->Name = L"btnLogOut";
			this->btnLogOut->Padding = System::Windows::Forms::Padding(8);
			this->btnLogOut->Size = System::Drawing::Size(168, 56);
			this->btnLogOut->TabIndex = 0;
			this->btnLogOut->Text = L"LogOut";
			this->btnLogOut->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->btnLogOut->UseVisualStyleBackColor = true;
			this->btnLogOut->Click += gcnew System::EventHandler(this, &Main::btnLogOut_Click);
			// 
			// summaryChrt
			// 
			chartArea1->Name = L"ChartArea1";
			this->summaryChrt->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->summaryChrt->Legends->Add(legend1);
			this->summaryChrt->Location = System::Drawing::Point(529, 116);
			this->summaryChrt->Name = L"summaryChrt";
			series1->ChartArea = L"ChartArea1";
			series1->Color = System::Drawing::Color::Lime;
			series1->Legend = L"Legend1";
			series1->Name = L"Budget";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::Red;
			series2->Legend = L"Legend1";
			series2->Name = L"Expense";
			this->summaryChrt->Series->Add(series1);
			this->summaryChrt->Series->Add(series2);
			this->summaryChrt->Size = System::Drawing::Size(1301, 679);
			this->summaryChrt->TabIndex = 8;
			this->summaryChrt->Text = L"Summary";
			// 
			// lblChart
			// 
			this->lblChart->BackColor = System::Drawing::Color::Transparent;
			this->lblChart->Font = (gcnew System::Drawing::Font(L"Sitka Display", 13.8F, System::Drawing::FontStyle::Bold));
			this->lblChart->ForeColor = System::Drawing::Color::Red;
			this->lblChart->Location = System::Drawing::Point(530, 798);
			this->lblChart->Name = L"lblChart";
			this->lblChart->Size = System::Drawing::Size(1301, 47);
			this->lblChart->TabIndex = 9;
			this->lblChart->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// budgetWarning
			// 
			this->budgetWarning->BalloonTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->budgetWarning->BalloonTipTitle = L"Warning";
			this->budgetWarning->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"budgetWarning.Icon")));
			this->budgetWarning->Text = L"Warning";
			this->budgetWarning->Visible = true;
			// 
			// btnInfo
			// 
			this->btnInfo->BackColor = System::Drawing::Color::Transparent;
			this->btnInfo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnInfo.BackgroundImage")));
			this->btnInfo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->btnInfo->Location = System::Drawing::Point(1756, 903);
			this->btnInfo->Name = L"btnInfo";
			this->btnInfo->Size = System::Drawing::Size(100, 58);
			this->btnInfo->TabIndex = 11;
			this->btnInfo->TabStop = false;
			this->btnInfo->Click += gcnew System::EventHandler(this, &Main::btnInfo_Click);
			// 
			// notifyStartMsgTimer
			// 
			this->notifyStartMsgTimer->Interval = 12000;
			this->notifyStartMsgTimer->Tick += gcnew System::EventHandler(this, &Main::NotifyMsg);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::Chocolate;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1898, 1029);
			this->Controls->Add(this->btnInfo);
			this->Controls->Add(this->lblChart);
			this->Controls->Add(this->summaryChrt);
			this->Controls->Add(this->grpExit);
			this->Controls->Add(this->grpExpense);
			this->Controls->Add(this->grpToDo);
			this->Controls->Add(this->lblHead);
			this->Controls->Add(this->grpUserDetail);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Manage Me";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->grpUserDetail->ResumeLayout(false);
			this->grpUserDetail->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgSetting))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->imgProfile))->EndInit();
			this->incomeAndExpenseGrp->ResumeLayout(false);
			this->toDoManagerGrp->ResumeLayout(false);
			this->grpToDo->ResumeLayout(false);
			this->grpExpense->ResumeLayout(false);
			this->grpExit->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->summaryChrt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->btnInfo))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnAddExpense_Click(System::Object^ sender, System::EventArgs^ e) {
		PersonalOrganizer::ExpenseForm expenseForm(this->user);
		expenseForm.ShowDialog();
		UpdateChart();
	}
	private: System::Void btnAddIncome_Click(System::Object^ sender, System::EventArgs^ e) {
		PersonalOrganizer::IncomeForm income(this->user);
		income.ShowDialog();
	}
	private: System::Void btnAddTask_Click(System::Object^ sender, System::EventArgs^ e) {
		PersonalOrganizer::AddTask addTaskForm(this->user);
		addTaskForm.ShowDialog();
	}
	private: void UpdateChart() {

		DBConnection^ connection = DBConnection::GetInstance();
		connection->OpenConnection();

		this->lblChart->Text = "This chart contains data from "+ user->NextDate.AddMonths(-1).ToString("yyyy-MM-dd") + " onwards.";

		summaryChrt->Series["Budget"]->Points->Clear();
		summaryChrt->Series["Expense"]->Points->Clear();


		for each (ExpenseCategory var in Enum::GetValues(ExpenseCategory::typeid))
		{
			String^ query = "SELECT amount FROM budget WHERE userID = @UserID AND category = @Category";

			SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

			command->Parameters->AddWithValue("@UserID", user->Id);
			command->Parameters->AddWithValue("@Category", var.ToString());

			SqlDataReader^ reader = command->ExecuteReader();

			try {
				if (reader->Read()) {
					summaryChrt->Series["Budget"]->Points->AddXY(var.ToString(), reader->GetDecimal(0));
				}
			}
			catch (Exception^) {
				MessageBox::Show("Bar graph invalid","Manage Me",MessageBoxButtons::OK);
			}
			finally {
				reader->Close();
			}
		}

		for each (ExpenseCategory var in Enum::GetValues(ExpenseCategory::typeid))
		{
			Decimal value = 0;
			String^ query = "SELECT SUM(amount) FROM expense WHERE userID = @UserID AND category = @Category AND date >= @Date";

			SqlCommand^ command = gcnew SqlCommand(query, connection->GetConnection());

			command->Parameters->AddWithValue("@UserID", user->Id);
			command->Parameters->AddWithValue("@Category", var.ToString());
			command->Parameters->AddWithValue("@Date", System::DateTime(user->NextDate.AddMonths(-1)));

			SqlDataReader^ reader = command->ExecuteReader();

			try {
				if (reader->Read()) {
					value = reader->GetDecimal(0);
				}
			}
			catch (Exception^) {
				
			}
			finally {
				summaryChrt->Series["Expense"]->Points->AddXY(var.ToString(), value);
				reader->Close();
			}
		}

		connection->CloseConnection();
	}
	private: System::Void btnMonthlyRepo_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PersonalOrganizer::MonthlyReport report(user);
			report.ShowDialog();
		}
		catch (Exception^ e) {
			Console::WriteLine(e->Message);
			MessageBox::Show("No Incomes & Expenses", "Manage Me", MessageBoxButtons::OK);
		}
	}
	private: System::Void btnReport_Click(System::Object^ sender, System::EventArgs^ e) {
		PersonalOrganizer::Report report(user);
		report.ShowDialog();
	}
	public: bool logOut = false;
	private: System::Void btnLogOut_Click(System::Object^ sender, System::EventArgs^ e) {
		logOut = true;
		this->Close();
	}
	private: System::Void btnViewTask_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PersonalOrganizer::ShowTask task(user);
			task.LoadData();
			task.ShowDialog();
		}
		catch (Exception^) {
			MessageBox::Show("No Tasks","Manage Me",MessageBoxButtons::OK);
		}
	}
	private: System::Void btnToday_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PersonalOrganizer::ShowTask task(user);
			task.Today();
			task.LoadData();
			task.ShowDialog();
		}
		catch (Exception^) {
			MessageBox::Show("No Tasks", "Manage Me", MessageBoxButtons::OK);
		}
	}
	private: System::Void btnBudget_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PersonalOrganizer::Budget budget(user);
			budget.ShowDialog();
			UpdateChart();
		}
		catch (Exception^) {
			MessageBox::Show("Can't add budgets","Manage Me",MessageBoxButtons::OK);
		}
	}
	private: System::Void setting_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			PersonalOrganizer::UserDetails userD(user);
			userD.ShowDialog();
			this->user = userD.user;
			SetUserDetails();
		}
		catch (Exception^) {}
	}
	private: void SetUserDetails() {
		this->lblName->Text = user->Name;
		this->txtAddress->Text = user->Address;
		this->txtEmail->Text = user->Email;
		this->txtPhone->Text = user->Phone;
		this->txtDate->Text = user->RegisteredDate.ToString("yyyy-MM-dd");
	}
	private: void MonthlyUpdate() {

		if (DateTime(user->NextDate).ToString("yyyy-MM-dd") == DateTime::Now.ToString("yyyy-MM-dd")) {
			
			DBConnection^ connection = DBConnection::GetInstance();
			connection->OpenConnection();

			String^ query = nullptr;
			SqlCommand^ insertCommand = nullptr;
			SqlTransaction^ transaction = nullptr;

			try
			{
				transaction = connection->GetConnection()->BeginTransaction();

				insertCommand = gcnew SqlCommand();
				insertCommand->Connection = connection->GetConnection();
				insertCommand->Transaction = transaction;

				query = "UPDATE budget SET amount=@Amount WHERE userID = @UserID AND category = @Category";
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


			try {

				String^ updateQuery = "UPDATE users SET nextUpdated_date = @NextDate WHERE Id = @UserID";
				SqlCommand^ updateCommand = gcnew SqlCommand(updateQuery, connection->GetConnection());

				updateCommand->Parameters->AddWithValue("@NextDate",System::DateTime(user->NextDate).AddMonths(1));
				updateCommand->Parameters->AddWithValue("@UserID", user->Id);

				
				updateCommand->ExecuteNonQuery();

			}
			catch (Exception^ ) {
				MessageBox::Show("Date update failure","Manage Me",MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
			finally {
				connection->CloseConnection();
			}

		}

	}
	private: void notify_Warning() {
		
		while (true) {

			Thread::Sleep(60000);

			DBConnection^ connection = DBConnection::GetInstance();
			connection->OpenConnection();
			
			String^ validateQuery = "IF EXISTS (SELECT task FROM toDo WHERE userID = @UserID AND date = @Today AND time > @Time) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
			SqlCommand^ decision = gcnew SqlCommand(validateQuery, connection->GetConnection());

			decision->Parameters->AddWithValue("@UserID", user->Id);
			decision->Parameters->AddWithValue("@Today", DateTime::Now.ToString("yyyy-MM-dd"));
			decision->Parameters->AddWithValue("@Time", DateTime::Now.ToString("hh:mm"));

			SqlDataReader^ answer = decision->ExecuteReader();

			if (answer->Read()) {
				if (answer->GetString(0) == "Exists") {
					answer->Close();

					String^ retriveQuery = "SELECT * FROM toDo WHERE userID = @UserID AND date = @Today AND time > @Time";
					SqlCommand^ command = gcnew SqlCommand(retriveQuery, connection->GetConnection());

					command->Parameters->AddWithValue("@UserID", user->Id);
					command->Parameters->AddWithValue("@Today", DateTime::Now.ToString("yyyy-MM-dd"));
					command->Parameters->AddWithValue("@Time", DateTime::Now.ToString("hh:mm"));

					SqlDataReader^ reader = command->ExecuteReader();

					try {
						while (reader->Read()) {
							this->budgetWarning->BalloonTipTitle = reader->GetString(1);
							DateTime time = reader->GetDateTime(3) + reader->GetTimeSpan(4);
							TimeSpan^ difference = time - DateTime::Now;
							if (difference->Hours > 0) {
								if (difference->Minutes > 0) {
									this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Hours + " hours " + difference->Minutes + " minutes remaining!";
								}
								else {
									this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Hours + " hours " + "  remaining!";
								}
							}
							else {
								this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Minutes + " minutes remaining!";
							}
							this->budgetWarning->ShowBalloonTip(200);
						}
					}
					catch (Exception^) {}
					finally { reader->Close(); connection->CloseConnection(); }

				}
			}
			else {
				break;
			}

			Thread::Sleep(120000);

		}

		/*String^ validateQuery = "IF EXISTS (SELECT task FROM toDo WHERE userID = @UserID AND date = @Today AND time > @Time) BEGIN SELECT 'Exists' AS result; END ELSE BEGIN SELECT 'Not exists' AS result; END";
		SqlCommand^ decision = gcnew SqlCommand(validateQuery, connection->GetConnection());

		decision->Parameters->AddWithValue("@UserID", user->Id);
		decision->Parameters->AddWithValue("@Today", DateTime::Now.ToString("yyyy-MM-dd"));
		decision->Parameters->AddWithValue("@Time", DateTime::Now.ToString("hh:mm"));

		SqlDataReader^ answer = decision->ExecuteReader();

		if (answer->Read()) {
			if (answer->GetString(0) == "Exists") {
				answer->Close();

				String^ retriveQuery = "SELECT * FROM toDo WHERE userID = @UserID AND date = @Today AND time > @Time";
				SqlCommand^ command = gcnew SqlCommand(retriveQuery, connection->GetConnection());

				command->Parameters->AddWithValue("@UserID", user->Id);
				command->Parameters->AddWithValue("@Today", DateTime::Now.ToString("yyyy-MM-dd"));
				command->Parameters->AddWithValue("@Time", DateTime::Now.ToString("hh:mm"));

				SqlDataReader^ reader = command->ExecuteReader();

				try {
					while (reader->Read()) {
						this->budgetWarning->BalloonTipTitle = reader->GetString(1);
						DateTime time = reader->GetDateTime(3) + reader->GetTimeSpan(4);
						TimeSpan^ difference = time - DateTime::Now;
						if (difference->Hours > 0) {
							if (difference->Minutes > 0) {
								this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Hours +" hours " + difference->Minutes + " minutes remaining!";
							}
							else {
								this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Hours + " hours " + "  remaining!";
							}
						}
						else {
							this->budgetWarning->BalloonTipText = "Today's Event\n" + difference->Minutes + " minutes remaining!";
						}
						this->budgetWarning->ShowBalloonTip(200);
					}
				}
				catch (Exception^) {}
				finally { reader->Close(); connection->CloseConnection(); }

			}
		}*/

	}
	private: void StartMsg_notify() {
		this->budgetWarning->BalloonTipTitle = "Reminder";
		this->budgetWarning->BalloonTipText = "Hello! "+ user->Name +". The current time is  " + DateTime::Now.ToString("hh : mm tt") + ". Don't forget to check your calendar for today's events!";
		this->budgetWarning->ShowBalloonTip(6000);
	}
	private: System::Void btnInfo_Click(System::Object^ sender, System::EventArgs^ e) {
		PersonalOrganizer::Info info;
		info.ShowDialog();
	}
	private: System::Void NotifyMsg(System::Object^ sender, System::EventArgs^ e) {
		this->notifyStartMsgTimer->Stop();
		StartMsg_notify();
	}
	private: Task^ StartRealTimeTaskAsync()
	{
		return Task::Run(gcnew Action(this, &Main::notify_Warning));
	}
};
}
