#pragma once

namespace WFtry2 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for moderator
	/// </summary>
	public ref class moderator : public System::Windows::Forms::Form
	{
	public:
		moderator(void)
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
		~moderator()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button_reject;




	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Time;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Customer;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Message;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Panel^ panel1;


	public:  delegate void DataPassedHandler(String^ data);
	public:  delegate void DataPassedHandler2(String^ data);
	public:  event DataPassedHandler^ DataPassedEvent;
	public:  event DataPassedHandler2^ DataPassedEvent2;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(moderator::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button_reject = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Time = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Customer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Message = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button1->Location = System::Drawing::Point(42, 428);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(163, 49);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Accept";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &moderator::button1_Click);
			// 
			// button_reject
			// 
			this->button_reject->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->button_reject->Font = (gcnew System::Drawing::Font(L"Century", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button_reject->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->button_reject->Location = System::Drawing::Point(233, 428);
			this->button_reject->Name = L"button_reject";
			this->button_reject->Size = System::Drawing::Size(163, 49);
			this->button_reject->TabIndex = 5;
			this->button_reject->Text = L"Reject";
			this->button_reject->UseVisualStyleBackColor = false;
			this->button_reject->Click += gcnew System::EventHandler(this, &moderator::button_reject_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Century", 11, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(147, 13);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(157, 18);
			this->label3->TabIndex = 3;
			this->label3->Text = L"Incoming message:";
			this->label3->Click += gcnew System::EventHandler(this, &moderator::label3_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Time, this->Customer,
					this->Message
			});
			this->dataGridView1->Location = System::Drawing::Point(22, 48);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(433, 182);
			this->dataGridView1->TabIndex = 7;
			this->dataGridView1->RowHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &moderator::dataGridView1_RowHeaderMouseClick);
			// 
			// Time
			// 
			this->Time->HeaderText = L"Time";
			this->Time->MinimumWidth = 6;
			this->Time->Name = L"Time";
			this->Time->ReadOnly = true;
			this->Time->Width = 125;
			// 
			// Customer
			// 
			this->Customer->HeaderText = L"Customer";
			this->Customer->MinimumWidth = 6;
			this->Customer->Name = L"Customer";
			this->Customer->ReadOnly = true;
			this->Customer->Width = 125;
			// 
			// Message
			// 
			this->Message->HeaderText = L"Message";
			this->Message->MinimumWidth = 6;
			this->Message->Name = L"Message";
			this->Message->ReadOnly = true;
			this->Message->Width = 125;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(22, 236);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->ReadOnly = true;
			this->richTextBox1->Size = System::Drawing::Size(435, 189);
			this->richTextBox1->TabIndex = 8;
			this->richTextBox1->Text = L"";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(117, 13);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(24, 30);
			this->pictureBox3->TabIndex = 14;
			this->pictureBox3->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->panel1->Controls->Add(this->pictureBox3);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->button_reject);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(453, 565);
			this->panel1->TabIndex = 15;
			// 
			// moderator
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(475, 506);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Font = (gcnew System::Drawing::Font(L"Century", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
			this->Name = L"moderator";
			this->Text = L"Moderator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	//private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	//	// Крок 1: Отримати текст з textBox1
	//	String^ inputText = textBox1->Text;

	//	// Крок 2: Розділити текст на слова
	//	array<String^>^ words = inputText->Split(' ');

	//	// Крок 3: Порахувати кількість слів
	//	int wordCount = words->Length;

	//	// Крок 4: Вивести кількість слів у label2
	//	label2->Text = wordCount.ToString();

	//	// Крок 5: Змінити колір тексту у label2, якщо кількість слів більша за 100
	//	if (wordCount > 2) {
	//		label2->ForeColor = System::Drawing::Color::Red;
	//	}
	//	else {
	//		// Якщо кількість слів менша або дорівнює 100, використовуємо стандартний колір
	//		label2->ForeColor = System::Drawing::SystemColors::ControlText;
	//	}
	//}

	public: System::Void CountWordsAndDisplay() {

	}

	DataGridView^ GetDataGridView() {
		return dataGridView1;
	}
	void SSetDataGridView(DataGridView^ source) {

		dataGridView1 = source;

	}

	/*private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
		
	}*/

	void SetDataGridView(DataGridView^ source) {
		// Очищаємо дані в dataGridViewDestination перед копіюванням
		dataGridView1->Rows->Clear();

		// Копіюємо дані з dataGridViewSource в dataGridViewDestination
		for each (DataGridViewRow ^ row in source->Rows) {
			if (row->IsNewRow) continue; // Пропускаємо останній рядок з "новим рядком"

			// Додаємо копію рядка в dataGridViewDestination
			DataGridViewRow^ newRow = gcnew DataGridViewRow();
			for (int i = 0; i < row->Cells->Count; i++) {
				newRow->Cells->Add(gcnew DataGridViewTextBoxCell());
				newRow->Cells[i]->Value = row->Cells[i]->Value;
			}
			dataGridView1->Rows->Add(newRow);
		}
	}



	private: System::Void dataGridView1_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
		if (dataGridView1->SelectedRows->Count > 0) { // Перевіряємо, чи є виділений рядок
			DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0]; // Отримуємо виділений рядок
			if (selectedRow->Cells[0]->Value == nullptr)
				return;
			richTextBox1->Clear();
			// Отримуємо дані виділеного рядка та відображаємо їх у TextBox
			richTextBox1->Text += selectedRow->Cells[0]->Value->ToString() + "\n";
			richTextBox1->Text += selectedRow->Cells[1]->Value->ToString() + "\n";
			richTextBox1->Text += selectedRow->Cells[2]->Value->ToString() + "\n";
		}
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (richTextBox1 == nullptr)
		return;
	if (dataGridView1->SelectedRows->Count > 0) { // Перевіряємо, чи є виділений рядок
		DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0]; // Отримуємо виділений рядок
		int selectedIndex = dataGridView1->SelectedRows[0]->Index;
		if (selectedRow->Cells[0]->Value == nullptr)
			return;

		String^ message = selectedRow->Cells[0]->Value->ToString() + " " + selectedRow->Cells[1]->Value->ToString() + " " + selectedRow->Cells[2]->Value->ToString();
		DataPassedEvent(message);
		dataGridView1->Rows->RemoveAt(selectedIndex);
		richTextBox1->Clear();
	}
	
	
}

	private: void DeleteMessageFromList(String^ time) {
		// Перевірка на вірність індексу перед видаленням
		for (int i = 0; i < dataGridView1->Rows->Count; i++) {
			if (dataGridView1->Rows[i]->Cells[0]->Value->ToString() == time) {
				dataGridView1->Rows->RemoveAt(i);
			}
		}

	}

private: System::Void button_reject_Click(System::Object^ sender, System::EventArgs^ e) {
	if (richTextBox1 == nullptr)
		return;
	if (dataGridView1->SelectedRows->Count > 0) { // Перевіряємо, чи є виділений рядок
		DataGridViewRow^ selectedRow = dataGridView1->SelectedRows[0]; // Отримуємо виділений рядок
		int selectedIndex = dataGridView1->SelectedRows[0]->Index;
		if (selectedRow->Cells[0]->Value == nullptr)
			return;

		String^ message = selectedRow->Cells[0]->Value->ToString() + " " + selectedRow->Cells[1]->Value->ToString() + " " + selectedRow->Cells[2]->Value->ToString();
		DataPassedEvent2(message);
		dataGridView1->Rows->RemoveAt(selectedIndex);
		richTextBox1->Clear();
	}
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
