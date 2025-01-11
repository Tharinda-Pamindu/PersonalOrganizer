#pragma once

namespace PersonalOrganizer {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for StartUp
	/// </summary>
	public ref class StartUp : public System::Windows::Forms::Form
	{
	public:
		StartUp(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->timer->Start();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartUp()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Timer^ timer;
	private: System::Windows::Forms::Label^ lblLoadingMsg;

	protected:
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartUp::typeid));
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->lblLoadingMsg = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->Interval = 12000;
			this->timer->Tick += gcnew System::EventHandler(this, &StartUp::animation_start);
			// 
			// lblLoadingMsg
			// 
			this->lblLoadingMsg->AutoSize = true;
			this->lblLoadingMsg->BackColor = System::Drawing::Color::Transparent;
			this->lblLoadingMsg->Font = (gcnew System::Drawing::Font(L"OCR A Extended", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblLoadingMsg->Location = System::Drawing::Point(423, 535);
			this->lblLoadingMsg->Name = L"lblLoadingMsg";
			this->lblLoadingMsg->Size = System::Drawing::Size(238, 18);
			this->lblLoadingMsg->TabIndex = 0;
			this->lblLoadingMsg->Text = L"Loading.... Please wait";
			// 
			// StartUp
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1061, 584);
			this->Controls->Add(this->lblLoadingMsg);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"StartUp";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"StartUp";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void animation_start(System::Object^ sender, System::EventArgs^ e) {
		this->timer->Stop();
		this->Close();
	}
	};
}
