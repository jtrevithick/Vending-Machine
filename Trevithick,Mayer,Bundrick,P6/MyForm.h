//James Trevithick				jtrevithick2@cnm.edu				//Trevithick,Mayer,BundrickP6
#pragma once
#include"VendingMachine.h"
#include"Dispenser.h"
#include"Logger.h"
#include"MoneyCtr.h"
#include"UtilityFunctions.h"
#include <iostream>
#include <string>
namespace TrevithickMayerBundrickP6 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	vendingMachine vend;
	MoneyCtr bank;
	Dispenser desp[5];
	Logger writeLogger;
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lHeader;
	protected:
	private: System::Windows::Forms::Label^  lDollarBills;
	private: System::Windows::Forms::Label^  lQuarters;
	private: System::Windows::Forms::Label^  lDimes;
	private: System::Windows::Forms::Label^  lNickels;




	private: System::Windows::Forms::Label^  lSnack;
	private: System::Windows::Forms::Button^  bBuy;
	private: System::Windows::Forms::Button^  bClear;
	private: System::Windows::Forms::Button^  bExit;
	private: System::Windows::Forms::RadioButton^  rPopTarts;
	private: System::Windows::Forms::RadioButton^  rSunChips;
	private: System::Windows::Forms::RadioButton^  rSnickers;
	private: System::Windows::Forms::RadioButton^  rBubbleYum;
	private: System::Windows::Forms::RadioButton^  rGranolaBar;

	private: System::Windows::Forms::PictureBox^  pbVending;
	private: System::Windows::Forms::TextBox^  tbResults;
	private: System::Windows::Forms::TextBox^  txtDolllar;
	private: System::Windows::Forms::TextBox^  txtQuarters;
	private: System::Windows::Forms::TextBox^  txtDimes;
	private: System::Windows::Forms::TextBox^  txtNickels;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->lHeader = (gcnew System::Windows::Forms::Label());
			this->lDollarBills = (gcnew System::Windows::Forms::Label());
			this->lQuarters = (gcnew System::Windows::Forms::Label());
			this->lDimes = (gcnew System::Windows::Forms::Label());
			this->lNickels = (gcnew System::Windows::Forms::Label());
			this->lSnack = (gcnew System::Windows::Forms::Label());
			this->bBuy = (gcnew System::Windows::Forms::Button());
			this->bClear = (gcnew System::Windows::Forms::Button());
			this->bExit = (gcnew System::Windows::Forms::Button());
			this->rPopTarts = (gcnew System::Windows::Forms::RadioButton());
			this->rSunChips = (gcnew System::Windows::Forms::RadioButton());
			this->rSnickers = (gcnew System::Windows::Forms::RadioButton());
			this->rBubbleYum = (gcnew System::Windows::Forms::RadioButton());
			this->rGranolaBar = (gcnew System::Windows::Forms::RadioButton());
			this->pbVending = (gcnew System::Windows::Forms::PictureBox());
			this->tbResults = (gcnew System::Windows::Forms::TextBox());
			this->txtDolllar = (gcnew System::Windows::Forms::TextBox());
			this->txtQuarters = (gcnew System::Windows::Forms::TextBox());
			this->txtDimes = (gcnew System::Windows::Forms::TextBox());
			this->txtNickels = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVending))->BeginInit();
			this->SuspendLayout();
			// 
			// lHeader
			// 
			this->lHeader->AutoSize = true;
			this->lHeader->Font = (gcnew System::Drawing::Font(L"Mistral", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lHeader->Location = System::Drawing::Point(59, 19);
			this->lHeader->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
			this->lHeader->Name = L"lHeader";
			this->lHeader->Size = System::Drawing::Size(846, 34);
			this->lHeader->TabIndex = 0;
			this->lHeader->Text = L"C++ Snack Machine-Pick your Snack! Please Enter Your Coins, then Select an Item";
			this->lHeader->Click += gcnew System::EventHandler(this, &MyForm::lHeader_Click);
			// 
			// lDollarBills
			// 
			this->lDollarBills->AutoSize = true;
			this->lDollarBills->Location = System::Drawing::Point(59, 78);
			this->lDollarBills->Name = L"lDollarBills";
			this->lDollarBills->Size = System::Drawing::Size(151, 34);
			this->lDollarBills->TabIndex = 1;
			this->lDollarBills->Text = L"Dollar Bills";
			// 
			// lQuarters
			// 
			this->lQuarters->AutoSize = true;
			this->lQuarters->Location = System::Drawing::Point(256, 78);
			this->lQuarters->Name = L"lQuarters";
			this->lQuarters->Size = System::Drawing::Size(120, 34);
			this->lQuarters->TabIndex = 2;
			this->lQuarters->Text = L"Quarters";
			// 
			// lDimes
			// 
			this->lDimes->AutoSize = true;
			this->lDimes->Location = System::Drawing::Point(413, 78);
			this->lDimes->Name = L"lDimes";
			this->lDimes->Size = System::Drawing::Size(94, 34);
			this->lDimes->TabIndex = 3;
			this->lDimes->Text = L"Dimes";
			// 
			// lNickels
			// 
			this->lNickels->AutoSize = true;
			this->lNickels->Location = System::Drawing::Point(562, 78);
			this->lNickels->Name = L"lNickels";
			this->lNickels->Size = System::Drawing::Size(104, 34);
			this->lNickels->TabIndex = 4;
			this->lNickels->Text = L"Nickels";
			// 
			// lSnack
			// 
			this->lSnack->AutoSize = true;
			this->lSnack->Location = System::Drawing::Point(59, 213);
			this->lSnack->Name = L"lSnack";
			this->lSnack->Size = System::Drawing::Size(187, 34);
			this->lSnack->TabIndex = 9;
			this->lSnack->Text = L"Select a Snack";
			// 
			// bBuy
			// 
			this->bBuy->Location = System::Drawing::Point(65, 633);
			this->bBuy->Name = L"bBuy";
			this->bBuy->Size = System::Drawing::Size(104, 40);
			this->bBuy->TabIndex = 10;
			this->bBuy->Text = L"BUY!";
			this->bBuy->UseVisualStyleBackColor = true;
			this->bBuy->Click += gcnew System::EventHandler(this, &MyForm::bBuy_Click);
			// 
			// bClear
			// 
			this->bClear->Location = System::Drawing::Point(262, 633);
			this->bClear->Name = L"bClear";
			this->bClear->Size = System::Drawing::Size(143, 41);
			this->bClear->TabIndex = 11;
			this->bClear->Text = L"CLEAR";
			this->bClear->UseVisualStyleBackColor = true;
			this->bClear->Click += gcnew System::EventHandler(this, &MyForm::bClear_Click);
			// 
			// bExit
			// 
			this->bExit->Location = System::Drawing::Point(499, 632);
			this->bExit->Name = L"bExit";
			this->bExit->Size = System::Drawing::Size(122, 41);
			this->bExit->TabIndex = 12;
			this->bExit->Text = L"EXIT";
			this->bExit->UseVisualStyleBackColor = true;
			this->bExit->Click += gcnew System::EventHandler(this, &MyForm::bExit_Click);
			// 
			// rPopTarts
			// 
			this->rPopTarts->AutoSize = true;
			this->rPopTarts->Checked = true;
			this->rPopTarts->Location = System::Drawing::Point(65, 270);
			this->rPopTarts->Name = L"rPopTarts";
			this->rPopTarts->Size = System::Drawing::Size(231, 38);
			this->rPopTarts->TabIndex = 13;
			this->rPopTarts->TabStop = true;
			this->rPopTarts->Text = L"Pop Tarts $1.60";
			this->rPopTarts->UseVisualStyleBackColor = true;
			// 
			// rSunChips
			// 
			this->rSunChips->AutoSize = true;
			this->rSunChips->Location = System::Drawing::Point(65, 345);
			this->rSunChips->Name = L"rSunChips";
			this->rSunChips->Size = System::Drawing::Size(236, 38);
			this->rSunChips->TabIndex = 14;
			this->rSunChips->Text = L"Sun Chips $1.25";
			this->rSunChips->UseVisualStyleBackColor = true;
			// 
			// rSnickers
			// 
			this->rSnickers->AutoSize = true;
			this->rSnickers->Location = System::Drawing::Point(65, 421);
			this->rSnickers->Name = L"rSnickers";
			this->rSnickers->Size = System::Drawing::Size(212, 38);
			this->rSnickers->TabIndex = 15;
			this->rSnickers->Text = L"Snickers $0.50";
			this->rSnickers->UseVisualStyleBackColor = true;
			// 
			// rBubbleYum
			// 
			this->rBubbleYum->AutoSize = true;
			this->rBubbleYum->Location = System::Drawing::Point(65, 479);
			this->rBubbleYum->Name = L"rBubbleYum";
			this->rBubbleYum->Size = System::Drawing::Size(264, 38);
			this->rBubbleYum->TabIndex = 16;
			this->rBubbleYum->Text = L"Bubble Yum $0.80";
			this->rBubbleYum->UseVisualStyleBackColor = true;
			// 
			// rGranolaBar
			// 
			this->rGranolaBar->AutoSize = true;
			this->rGranolaBar->Location = System::Drawing::Point(65, 539);
			this->rGranolaBar->Name = L"rGranolaBar";
			this->rGranolaBar->Size = System::Drawing::Size(260, 38);
			this->rGranolaBar->TabIndex = 17;
			this->rGranolaBar->Text = L"Granola Bar $0.95";
			this->rGranolaBar->UseVisualStyleBackColor = true;
			// 
			// pbVending
			// 
			this->pbVending->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVending.Image")));
			this->pbVending->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbVending.InitialImage")));
			this->pbVending->Location = System::Drawing::Point(335, 180);
			this->pbVending->Name = L"pbVending";
			this->pbVending->Size = System::Drawing::Size(538, 423);
			this->pbVending->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pbVending->TabIndex = 19;
			this->pbVending->TabStop = false;
			// 
			// tbResults
			// 
			this->tbResults->Location = System::Drawing::Point(14, 679);
			this->tbResults->Multiline = true;
			this->tbResults->Name = L"tbResults";
			this->tbResults->ReadOnly = true;
			this->tbResults->Size = System::Drawing::Size(891, 109);
			this->tbResults->TabIndex = 20;
			// 
			// txtDolllar
			// 
			this->txtDolllar->Location = System::Drawing::Point(65, 116);
			this->txtDolllar->Name = L"txtDolllar";
			this->txtDolllar->Size = System::Drawing::Size(132, 42);
			this->txtDolllar->TabIndex = 21;
			// 
			// txtQuarters
			// 
			this->txtQuarters->Location = System::Drawing::Point(262, 116);
			this->txtQuarters->Name = L"txtQuarters";
			this->txtQuarters->Size = System::Drawing::Size(114, 42);
			this->txtQuarters->TabIndex = 22;
			// 
			// txtDimes
			// 
			this->txtDimes->Location = System::Drawing::Point(419, 116);
			this->txtDimes->Name = L"txtDimes";
			this->txtDimes->Size = System::Drawing::Size(109, 42);
			this->txtDimes->TabIndex = 23;
			// 
			// txtNickels
			// 
			this->txtNickels->Location = System::Drawing::Point(566, 116);
			this->txtNickels->Name = L"txtNickels";
			this->txtNickels->Size = System::Drawing::Size(110, 42);
			this->txtNickels->TabIndex = 24;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(17, 34);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(910, 790);
			this->Controls->Add(this->txtNickels);
			this->Controls->Add(this->txtDimes);
			this->Controls->Add(this->txtQuarters);
			this->Controls->Add(this->txtDolllar);
			this->Controls->Add(this->tbResults);
			this->Controls->Add(this->pbVending);
			this->Controls->Add(this->rGranolaBar);
			this->Controls->Add(this->rBubbleYum);
			this->Controls->Add(this->rSnickers);
			this->Controls->Add(this->rSunChips);
			this->Controls->Add(this->rPopTarts);
			this->Controls->Add(this->bExit);
			this->Controls->Add(this->bClear);
			this->Controls->Add(this->bBuy);
			this->Controls->Add(this->lSnack);
			this->Controls->Add(this->lNickels);
			this->Controls->Add(this->lDimes);
			this->Controls->Add(this->lQuarters);
			this->Controls->Add(this->lDollarBills);
			this->Controls->Add(this->lHeader);
			this->Font = (gcnew System::Drawing::Font(L"Baskerville Old Face", 18, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"MyForm";
			this->Text = L"Trevithick,Mayer,BundrickP6 The Snack Machine";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbVending))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void bClear_Click(System::Object^  sender, System::EventArgs^  e) {

		//clear the results and money
		tbResults->Clear();
		txtDolllar->Clear();
		txtDimes->Clear();
		txtNickels->Clear();
		txtQuarters->Clear();
		
		//rest all radio buttons
		rPopTarts->Checked = true;
		rSunChips->Checked = false;
		rSnickers->Checked = false;
		rBubbleYum->Checked = false;
		rGranolaBar->Checked = false;



	}
private: System::Void bExit_Click(System::Object^  sender, System::EventArgs^  e) {

	Application::Exit();
}
private: System::Void lHeader_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void bBuy_Click(System::Object^  sender, System::EventArgs^  e) {
	//int do || = Decimal::ToInt32(txtDolllar->);
	std::string dollar, quarter, dimes, nickel;
	To_string(txtDolllar->Text, dollar);
	To_string(txtQuarters->Text, quarter);
	To_string(txtDimes->Text, dimes);
	To_string(txtNickels->Text, nickel);
	int doll = 0, quar = 0, dime = 0, nick = 0;
	try {
		doll = std::stoi(dollar);
		quar = std::stoi(quarter);
		dime = std::stoi(dimes);
		nick = std::stoi(nickel);
	}
	catch (exception e) {
		//std::cout << "Values Need to be a number";
		
	}
	int selection = 0;
	if (rPopTarts->Checked) selection = 0;
	else if (rSunChips->Checked) selection = 1;
	else if (rSnickers->Checked) selection = 2;
	else if (rBubbleYum->Checked) selection = 3;
	else if (rGranolaBar->Checked) selection = 4;
	vend.SetPurchase(doll, quar, dime, nick, selection);

	tbResults->Text = gcnew String(vend.GetDispenseString().c_str());
	
	
}
};
}
