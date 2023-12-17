#pragma once
#include <fstream>
#include "Client.h"


namespace WFtry2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO;
	/// <summary>
	/// Summary for Form3
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}
	/*private:  String^ filePath = "UserData.txt";*/
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox_name;

	private: System::Windows::Forms::TextBox^ textBox_Surname;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox_password;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox_repeatpassword;
	private: System::Windows::Forms::Panel^ panel1;

	public:  delegate void DataPassedHandler(String^ data);
	public:  event DataPassedHandler^ DataPassedEvent;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_name = (gcnew System::Windows::Forms::TextBox());
			this->textBox_Surname = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox_repeatpassword = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::LightSlateGray;
			this->button1->Location = System::Drawing::Point(106, 287);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(167, 47);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form3::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(25, 80);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(67, 23);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Name";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 13);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(99, 23);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Surname";
			// 
			// textBox_name
			// 
			this->textBox_name->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_name->Location = System::Drawing::Point(29, 106);
			this->textBox_name->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_name->Multiline = true;
			this->textBox_name->Name = L"textBox_name";
			this->textBox_name->Size = System::Drawing::Size(327, 32);
			this->textBox_name->TabIndex = 6;
			// 
			// textBox_Surname
			// 
			this->textBox_Surname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->textBox_Surname->Location = System::Drawing::Point(29, 43);
			this->textBox_Surname->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_Surname->Multiline = true;
			this->textBox_Surname->Name = L"textBox_Surname";
			this->textBox_Surname->Size = System::Drawing::Size(327, 35);
			this->textBox_Surname->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(25, 145);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 23);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Password";
			// 
			// textBox_password
			// 
			this->textBox_password->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_password->Location = System::Drawing::Point(28, 240);
			this->textBox_password->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_password->Multiline = true;
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(327, 32);
			this->textBox_password->TabIndex = 10;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(25, 212);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(215, 23);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Repeat the password";
			// 
			// textBox_repeatpassword
			// 
			this->textBox_repeatpassword->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_repeatpassword->Location = System::Drawing::Point(28, 171);
			this->textBox_repeatpassword->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox_repeatpassword->Multiline = true;
			this->textBox_repeatpassword->Name = L"textBox_repeatpassword";
			this->textBox_repeatpassword->Size = System::Drawing::Size(326, 34);
			this->textBox_repeatpassword->TabIndex = 12;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->textBox_repeatpassword);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->textBox_Surname);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->textBox_password);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->textBox_name);
			this->panel1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(377, 347);
			this->panel1->TabIndex = 14;
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(400, 371);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Form3";
			this->Text = L"Registration";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}

		private: bool IsUserInFile(String^ surname, String^ name) {
			try {
				String^ filePath = "";
				StreamReader^ reader = gcnew StreamReader(filePath);

				while (!reader->EndOfStream) {
					String^ line = reader->ReadLine();
					array<String^>^ words = line->Split(' ');
					if (surname == words[0] && name == words[1])
					{
						reader->Close();
						return true;
					}
						
				}

				// Закриваємо файл
				reader->Close();

				return false;
			}
			catch (Exception^ e) {
				Console::WriteLine("Сталася помилка: {0}", e->Message);
			}
		}
		/*private: bool WriteInFile() {

		}*/
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ filePath = "";
		if (textBox_Surname->Text == "" || textBox_name->Text == "" || textBox_password->Text == "" || textBox_repeatpassword->Text == "") {
			MessageBox::Show("Не заповнені текстові поля");
			return;
		}
		if (textBox_Surname->Text->Contains(" ") || textBox_name->Text->Contains(" ") || textBox_password->Text->Contains(" ") || textBox_repeatpassword->Text->Contains(" ")) {
			MessageBox::Show("Текстові поля не повинні містити пробіли");
			return;
		}
		if (textBox_password->Text != textBox_repeatpassword->Text) {
			MessageBox::Show("Повторний пороль не співпадає з попереднім");
			return;
		}
		/*if (IsUserInFile(textBox_Surname->Text, textBox_name->Text) == true) {
			MessageBox::Show("Користувач з таким самим прізвищем та ім'ям вже є");
			return;
		}*/
		
		textBox_name;
		textBox_password;
		textBox_repeatpassword;
		
		DataPassedEvent(textBox_Surname->Text + " " + textBox_name->Text + " " +  textBox_password->Text);
		this->Close();
		return;


	}
		   public: String^ GetTextBox1Value()
		   {
			   return textBox_Surname->Text;
		   }

	public: String^ GetTextBox2Value()
	{
		return textBox_name->Text;
	}

};
}
