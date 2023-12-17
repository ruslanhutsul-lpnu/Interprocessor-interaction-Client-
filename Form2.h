#pragma once
#include "Client.h"
#include "moderator.h"

namespace WFtry2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
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
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox_surname;
	protected:
		//private:  String^ filePath = "UserData.txt";
	private: System::Windows::Forms::TextBox^ textBox_name;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_password;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel1;

	public:  delegate void DataPassedHandler(String^ data);
	public:  event DataPassedHandler^ DataPassedEvent;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->textBox_surname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox_surname
			// 
			this->textBox_surname->Location = System::Drawing::Point(17, 41);
			this->textBox_surname->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_surname->Multiline = true;
			this->textBox_surname->Name = L"textBox_surname";
			this->textBox_surname->Size = System::Drawing::Size(253, 42);
			this->textBox_surname->TabIndex = 0;
			// 
			// textBox_name
			// 
			this->textBox_name->Location = System::Drawing::Point(17, 133);
			this->textBox_name->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_name->Multiline = true;
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(253, 39);
			this->textBox_name->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(16, 4);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 18);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Surname";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(13, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 18);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(89)), static_cast<System::Int32>(static_cast<System::Byte>(145)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->button1->Location = System::Drawing::Point(144, 378);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(95, 38);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(13, 186);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(76, 18);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Password";
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(17, 223);
			this->textBox_password->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_password->Multiline = true;
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(253, 39);
			this->textBox_password->TabIndex = 5;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Century Gothic", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(125, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Authorization";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(179)), static_cast<System::Int32>(static_cast<System::Byte>(235)),
				static_cast<System::Int32>(static_cast<System::Byte>(242)));
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox_password);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox_name);
			this->panel1->Controls->Add(this->textBox_surname);
			this->panel1->Location = System::Drawing::Point(39, 52);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(300, 312);
			this->panel1->TabIndex = 9;
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 441);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MyForm1";
			this->Text = L"Form2";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		// ...
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox_surname->Text == "" || textBox_name->Text == "" || textBox_password->Text == "") {
			MessageBox::Show("Please, enter your data");
			return;
		}
		if (textBox_surname->Text->Contains(" ") || textBox_name->Text->Contains(" ") || textBox_password->Text->Contains(" ")) {
			MessageBox::Show("Текстові поля не повинні містити пробіли");
			return;
		}

		/*if (checkBox1->Checked) {
			
			moderator^ moderatorForm = gcnew moderator();
			moderatorForm->Show();
			
		}*/

		DataPassedEvent(textBox_surname->Text + " " + textBox_name->Text + " " + textBox_password->Text);
		this->Close();
	}

//}
		   // ...


		//private: bool IsUserInFile(String^ surname, String^ name, String^ password) {
		//	try {
		//		String^ filePath = "";
		//		StreamReader^ reader = gcnew StreamReader(filePath);

		//		while (!reader->EndOfStream) {
		//			String^ line = reader->ReadLine();
		//			array<String^>^ words = line->Split(' ');
		//			if (surname == words[0] && name == words[1])
		//			{
		//				if (password == words[2])
		//				{
		//				reader->Close();
		//				return true;
		//				}
		//				else {
		//					reader->Close();
		//					MessageBox::Show("Неправильний пароль");
		//					return false;
		//				}
		//			}

		//		}

		//		// Закриваємо файл
		//		reader->Close();
		//		MessageBox::Show("Користувача з таким самим прізвищем та ім'ям нема");
		//		return false;
		//	}
		//	catch (Exception^ e) {
		//		Console::WriteLine("Сталася помилка: {0}", e->Message);
		//	}
		//}


	public:
		String^ GetTextBox1Value()
		{
			return textBox_surname->Text;
		}

		String^ GetTextBox2Value()
		{
			return textBox_name->Text;
		}

	};
}
