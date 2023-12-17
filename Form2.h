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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// textBox_surname
			// 
			this->textBox_surname->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_surname->Location = System::Drawing::Point(16, 42);
			this->textBox_surname->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_surname->Multiline = true;
			this->textBox_surname->Name = L"textBox_surname";
			this->textBox_surname->Size = System::Drawing::Size(353, 42);
			this->textBox_surname->TabIndex = 0;
			this->textBox_surname->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox_surname_TextChanged);
			// 
			// textBox_name
			// 
			this->textBox_name->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_name->Location = System::Drawing::Point(16, 127);
			this->textBox_name->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_name->Multiline = true;
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(353, 42);
			this->textBox_name->TabIndex = 1;
			this->textBox_name->TextChanged += gcnew System::EventHandler(this, &MyForm1::textBox_name_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(13, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Surname";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(13, 101);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Name";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSlateGray;
			this->button1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(110, 266);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 46);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(13, 184);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 23);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Password";
			// 
			// textBox_password
			// 
			this->textBox_password->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_password->Location = System::Drawing::Point(17, 210);
			this->textBox_password->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->textBox_password->Multiline = true;
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(353, 42);
			this->textBox_password->TabIndex = 5;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox_password);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->textBox_name);
			this->panel1->Controls->Add(this->textBox_surname);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(386, 332);
			this->panel1->TabIndex = 9;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm1::panel1_Paint);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(410, 354);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"MyForm1";
			this->Text = L"Authorization";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

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

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void textBox_surname_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox_name_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
