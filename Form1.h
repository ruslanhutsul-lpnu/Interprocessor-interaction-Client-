#pragma once
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include <sstream>
#include <iostream>
#include <string>
#include <conio.h>
#include <vector>
#include <msclr/marshal_cppstd.h>
#include <algorithm>
#include "Form2.h"
#include "Form3.h"
#include <tlhelp32.h>
#include "Client.h"
#include <thread>
#include <msclr/marshal_cppstd.h>
// Покажчик на манагований об'єкт, замість самого об'єкта


namespace WFtry2 {

	using namespace System::Threading;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace System::Runtime::InteropServices;
	using namespace msclr::interop;
	//using namespace std;
	using namespace System::Timers;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: moderator^ moderatorForm;

		   static Client^ client = gcnew Client();

	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;


		   String^ lastReceivedMessage;
		   // Таймер для перевірки сервера
		   System::Timers::Timer^ clCheckTimer;
	private: System::Windows::Forms::MenuStrip^ menuStrip1;

	private: System::Timers::Timer^ timer;
	private: System::Windows::Forms::ToolStripMenuItem^ logOutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ loginToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ signToolStripMenuItem;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	/*private: System::Windows::Forms::ToolStripMenuItem^ loginToolStripMenuItem;*/
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

		}
	public:
		void InitializeComponent(void)
		{
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->loginToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->signToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->logOutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer = (gcnew System::Timers::Timer());
			this->menuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->loginToolStripMenuItem,
					this->signToolStripMenuItem, this->logOutToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(776, 26);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			this->menuStrip1->ItemClicked += gcnew System::Windows::Forms::ToolStripItemClickedEventHandler(this, &MyForm::menuStrip1_ItemClicked);
			// 
			// loginToolStripMenuItem
			// 
			this->loginToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->loginToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)), static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->loginToolStripMenuItem->Name = L"loginToolStripMenuItem";
			this->loginToolStripMenuItem->Size = System::Drawing::Size(62, 22);
			this->loginToolStripMenuItem->Text = L"LogIn";
			this->loginToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::loginToolStripMenuItem_Click_1);
			// 
			// signToolStripMenuItem
			// 
			this->signToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->signToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)), static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->signToolStripMenuItem->Name = L"signToolStripMenuItem";
			this->signToolStripMenuItem->Size = System::Drawing::Size(53, 22);
			this->signToolStripMenuItem->Text = L"Sign";
			this->signToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::signToolStripMenuItem_Click);
			// 
			// logOutToolStripMenuItem
			// 
			this->logOutToolStripMenuItem->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->logOutToolStripMenuItem->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)),
				static_cast<System::Int32>(static_cast<System::Byte>(101)), static_cast<System::Int32>(static_cast<System::Byte>(115)));
			this->logOutToolStripMenuItem->Name = L"logOutToolStripMenuItem";
			this->logOutToolStripMenuItem->Size = System::Drawing::Size(75, 22);
			this->logOutToolStripMenuItem->Text = L"LogOut";
			this->logOutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::logOutToolStripMenuItem_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(202)),
				static_cast<System::Int32>(static_cast<System::Byte>(219)));
			this->panel1->Controls->Add(this->richTextBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(360, 53);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(404, 477);
			this->panel1->TabIndex = 1;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(40, 45);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(343, 405);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(146, 14);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 18);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Latest tweets";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->label2->Location = System::Drawing::Point(21, 53);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 19);
			this->label2->TabIndex = 2;
			this->label2->Text = L"I am";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century Gothic", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->label3->Location = System::Drawing::Point(80, 53);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(96, 21);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Undefined";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(25, 177);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(298, 159);
			this->textBox2->TabIndex = 4;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(54)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(117)));
			this->label4->Location = System::Drawing::Point(34, 144);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(97, 18);
			this->label4->TabIndex = 5;
			this->label4->Text = L"What\'s new\?";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(106)), static_cast<System::Int32>(static_cast<System::Byte>(171)),
				static_cast<System::Int32>(static_cast<System::Byte>(108)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(127, 355);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(86, 46);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Post";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// timer
			// 
			this->timer->Enabled = true;
			this->timer->SynchronizingObject = this;
			// 
			// MyForm
			// 
			this->ClientSize = System::Drawing::Size(776, 558);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing_1);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->timer))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

			this->Load += gcnew EventHandler(this, &MyForm::MyForm_Load);
			System::Timers::Timer^ timer = gcnew System::Timers::Timer();
			timer->Interval = 1000; // інтервал в мілісекундах
			timer->Elapsed += gcnew ElapsedEventHandler(this, &MyForm::OnTimerTick);
			timer->AutoReset = true; // встановлення автоматичного перезапуску таймера
			timer->Enabled = true;
		}
#pragma endregion

		//this->Load += gcnew EventHandler(this, &MyForm::MyForm_Load);
		//System::Timers::Timer^ timer = gcnew System::Timers::Timer();
		//timer->Interval = 1000; // інтервал в мілісекундах
		//timer->Elapsed += gcnew ElapsedEventHandler(this, &MyForm::OnTimerTick);
		//timer->AutoReset = true; // встановлення автоматичного перезапуску таймера
		//timer->Enabled = true;
		void MyForm_Load(Object^ sender, EventArgs^ e) {
			client = gcnew Client();
			// Запускаємо сервер у окремому потоці
			Thread^ serverThread = gcnew Thread(gcnew ThreadStart(client, &Client::ConnectToServer));
			serverThread->IsBackground = true; // Щоб при закритті форми припинити роботу сервера
			serverThread->Start();
		}

		void OnTimerTick(System::Object^ source, System::Timers::ElapsedEventArgs^ e) {
			
			String^ receivedMessage = client->ReceiveData();
			if (!(receivedMessage == "")) {
				CheckMessenge(receivedMessage);
			}
			
			
			
		}

		/*void UpdateTextBox(String^ message) {
			textBox1->Text = message;
		}*/



	private: int CheckMessenge(String^ messenge) {
		array<String^>^ words = messenge->Split(' ');
		/*MessageBox::Show("client" + messenge);*/
		if (words[0] == "SIGN")
		{


			MessageBox::Show(messenge);
		}
		else if (words[0] == "LOGIN")
		{
			if (words[1] == "true") {
				label3->Text = words[2] + " " + words[3];
				client->SetAccess(true);
				/*MessageBox::Show("LOGIN true");*/
			}
			else if (words[1] == "moder") {
				label3->Text = words[2] + " " + words[3];
				client->SetAccess(true);
				Thread^ serverThread = gcnew Thread(gcnew ThreadStart(this, &MyForm::CreateModer));
				serverThread->IsBackground = true; // Щоб при закритті форми припинити роботу сервера
				serverThread->Start();

				/*MessageBox::Show("LOGIN moder");*/
				
			}
			else
				MessageBox::Show(messenge);
		}
		else if (words[0] == "MESSAGE")
		{
			/*MessageBox::Show(messenge);*/
			richTextBox1->Text += JoinWordsFromIndex(words, 1);
			richTextBox1->Text += "\n\n";
		}
		else if (words[0] == "UPDATE" && client->GetAccess() == true)
		{
			DataGridView^ dataGridView;
			dataGridView = moderatorForm->GetDataGridView();
			dataGridView->Rows->Add(words[1] + " " + words[2], words[3] + " " + words[4], JoinWordsFromIndex(words, 5));
			moderatorForm->SSetDataGridView(dataGridView);
		}
		else if (words[0] == "LOAD" && client->GetAccess() == true)
		{

			String^ input = JoinWordsFromIndex(words, 1);


			moderatorForm->SSetDataGridView(FillDataGridViewFromString(input));

		}
		else if (words[0] == "LOADCHAT") {
			richTextBox1->Text = JoinWordsFromIndex(words, 1);
		}
		else if (words[0] == "REJECT")
		{
			MessageBox::Show(messenge);
		
		}
		else
			/*MessageBox::Show("okkk" + messenge);*/
		return 1;
	}

		   //void DDD(DataGridView^ dataGridView) {
			  // String^ dataAsString = "";

			  // // Проходимо по всіх рядках у dataGridView1
			  // for each (DataGridViewRow ^ row in dataGridView->Rows) {
				 //  if (row->IsNewRow) continue;


				 //  for each (DataGridViewCell ^ cell in row->Cells) {

					//   dataAsString += cell->Value->ToString() + " ";
				 //  }

				 //  dataAsString += "\n";
			  // }
			  ///* MessageBox::Show(dataAsString);*/
		   //}

		   DataGridView^ FillDataGridViewFromString(String^ dataAsString) {
			   DataGridView^ dataGridView;
			   dataGridView = moderatorForm->GetDataGridView();

			   array<String^>^ rows = dataAsString->Split('\n'); // Розділяємо рядок на окремі рядки

			   if (rows->Length > 0) {
				   // Розділяємо кожний рядок на окремі значення за пробілом та додаємо їх у dataGridView
				   for (int i = 0; i < rows->Length; i++) {
					   array<String^>^ cells = rows[i]->Split(' '); // Розділяємо кожний рядок на комірки
					   String^ str = JoinWordsFromIndex(cells, 4);
					   /*MessageBox::Show(cells[0] + " " + cells[1] + cells[2] + " " + cells[3] + str);*/
					   dataGridView->Rows->Add(cells[0] + " " + cells[1], cells[2] + " " + cells[3], str);
				   }
			   }
			   /*DDD(dataGridView);*/
			   return dataGridView;
		   }








		   String^ JoinWordsFromIndex(array<String^>^ words, int startIndex) {
			   if (startIndex >= words->Length) {
				   return ""; // Повернути порожній рядок, якщо початковий індекс виходить за межі масиву
			   }

			   String^ result = "";
			   for (int i = startIndex; i < words->Length; i++) {
				   result += words[i] + " ";
			   }

			   return result->Trim(); // Повертаємо рядок, обрізаючи останній пробіл за допомогою Trim()
		   }

	

		   //System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
			  // // Виклик методу відключення клієнтів від сервера
			  // client->DisconnectFromServer();

		   //}

	private: void CreateModer() {
		moderatorForm = gcnew moderator();
		this->moderatorForm->DataPassedEvent += gcnew moderator::DataPassedHandler(this, &MyForm::ModerMessageAccept);
		this->moderatorForm->DataPassedEvent2 += gcnew moderator::DataPassedHandler2(this, &MyForm::ModerMessageReject);
		moderatorForm->ShowDialog();
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: void SignMessage(String^ input) {
		String^ message = "SIGN" + " " + input;
		msclr::interop::marshal_context context;
		const char* charStr = context.marshal_as<const char*>(message);
		client->SendToServer(charStr);
	}

	private: void LogInMessage(String^ input) {
		if (client->IsConnect() != true)
		{

			Thread^ serverThread = gcnew Thread(gcnew ThreadStart(client, &Client::ConnectToServer));
			serverThread->IsBackground = true; // Щоб при закритті форми припинити роботу сервера
			serverThread->Start();
			/*MessageBox::Show("NO CONNECT");*/
		}
		/*MessageBox::Show("YE CONNECT");*/

		String^ message = "LOGIN" + " " + input;
		msclr::interop::marshal_context context;
		const char* charStr = context.marshal_as<const char*>(message);
		client->SendToServer(charStr);
	}
	private: void  ModerMessageAccept(String^ input) {
		String^ message = "ACCEPT" + " " + input;
		msclr::interop::marshal_context context;
		const char* charStr = context.marshal_as<const char*>(message);
		client->SendToServer(charStr);
	}
	private: void  ModerMessageReject(String^ input) {
		String^ message = "REJECT" + " " + input;
		msclr::interop::marshal_context context;
		const char* charStr = context.marshal_as<const char*>(message);
		client->SendToServer(charStr);
	}



	private: System::Void button_sign_Click(System::Object^ sender, System::EventArgs^ e) {
		Form3^ form3 = gcnew Form3;
		form3->DataPassedEvent += gcnew Form3::DataPassedHandler(this, &MyForm::SignMessage);

		form3->ShowDialog();
		form3->Close();



		/*label3->Text = form3->GetTextBox1Value() + " " + form3->GetTextBox2Value();*/
	}
	private: System::Void button_sent_Click(System::Object^ sender, System::EventArgs^ e) {
		client->SendToServer("Test messange");
	}


	private: System::Void MyForm_FormClosing_1(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		//MessageBox::Show("yee");
		client->DisconnectFromServer();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == "")
			return;
		if (client->GetAccess() == false)
		{
			MessageBox::Show("You don`t habe access");
			return;
		}
		DateTime currentTime = DateTime::Now;
		String^ currentDateTime = currentTime.ToString();

		String^ managedString = "MESSAGE " + currentDateTime + " " + label3->Text + " " + textBox2->Text; // Ваш String^
		marshal_context context;
		const char* charStr = context.marshal_as<const char*>(managedString);
		client->SendToServer(charStr);
		Sleep(100);
		textBox2->Text = "";
		
	}
	private: System::Void menuStrip1_ItemClicked(System::Object^ sender, System::Windows::Forms::ToolStripItemClickedEventArgs^ e) {
	}
private: System::Void signToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Form3^ form3 = gcnew Form3;
	form3->DataPassedEvent += gcnew Form3::DataPassedHandler(this, &MyForm::SignMessage);

	form3->ShowDialog();
	form3->Close();
}

private: System::Void loginToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (client->GetAccess() == true)
	{
		MessageBox::Show("You have already logged in");
		return;
	}
	MyForm1^ form2 = gcnew MyForm1;
	form2->DataPassedEvent += gcnew MyForm1::DataPassedHandler(this, &MyForm::LogInMessage);
	form2->ShowDialog();
}
private: System::Void loginToolStripMenuItem_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (client->GetAccess() == true)
	{
		MessageBox::Show("You have already logged in");
		return;
	}
	MyForm1^ form2 = gcnew MyForm1;
	form2->DataPassedEvent += gcnew MyForm1::DataPassedHandler(this, &MyForm::LogInMessage);
	form2->ShowDialog();
}
private: System::Void logOutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	if (client->GetAccess() == false)
	{
		MessageBox::Show("You have already logged out");
		return;
	}
	label3->Text = "Undefined";
	client->SetAccess(false);
	client->DisconnectFromServer();
}
};
}