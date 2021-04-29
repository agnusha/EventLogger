#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace std;

namespace EventLoggerDesktop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CreateForm
	/// </summary>
	public ref class CreateForm : public System::Windows::Forms::Form
	{
	public:
		CreateForm(System::Windows::Forms::Form^ formParent)
		{
			otherform = formParent;
			InitializeComponent();
		}
		CreateForm(void)
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
		~CreateForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
		   System::Windows::Forms::Form^ otherform;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Required method for Designer support - do not modify
		   /// the contents of this method with the code editor.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->label5 = (gcnew System::Windows::Forms::Label());
			   this->button1 = (gcnew System::Windows::Forms::Button());
			   this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			   this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			   this->SuspendLayout();
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Location = System::Drawing::Point(220, 25);
			   this->label1->Name = L"label1";
			   this->label1->Size = System::Drawing::Size(100, 20);
			   this->label1->TabIndex = 0;
			   this->label1->Text = L"Create event";
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Location = System::Drawing::Point(59, 81);
			   this->label2->Name = L"label2";
			   this->label2->Size = System::Drawing::Size(43, 20);
			   this->label2->TabIndex = 1;
			   this->label2->Text = L"Type";
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Location = System::Drawing::Point(59, 154);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(23, 20);
			   this->label3->TabIndex = 2;
			   this->label3->Text = L"Id";
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Location = System::Drawing::Point(59, 225);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(60, 20);
			   this->label4->TabIndex = 3;
			   this->label4->Text = L"Source";
			   // 
			   // label5
			   // 
			   this->label5->AutoSize = true;
			   this->label5->Location = System::Drawing::Point(59, 300);
			   this->label5->Name = L"label5";
			   this->label5->Size = System::Drawing::Size(89, 20);
			   this->label5->TabIndex = 4;
			   this->label5->Text = L"Description";
			   // 
			   // button1
			   // 
			   this->button1->Location = System::Drawing::Point(502, 175);
			   this->button1->Name = L"button1";
			   this->button1->Size = System::Drawing::Size(103, 49);
			   this->button1->TabIndex = 5;
			   this->button1->Text = L"Submit";
			   this->button1->UseVisualStyleBackColor = true;
			   this->button1->Click += gcnew System::EventHandler(this, &CreateForm::button1_Click);
			   // 
			   // listBox1
			   // 
			   this->listBox1->FormattingEnabled = true;
			   this->listBox1->ItemHeight = 20;
			   this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"SUCCESS", L"ERROR", L"WARNING", L"INFORMATION" });
			   this->listBox1->Location = System::Drawing::Point(154, 77);
			   this->listBox1->Name = L"listBox1";
			   this->listBox1->Size = System::Drawing::Size(257, 24);
			   this->listBox1->TabIndex = 6;
			   // 
			   // numericUpDown1
			   // 
			   this->numericUpDown1->Location = System::Drawing::Point(154, 148);
			   this->numericUpDown1->Name = L"numericUpDown1";
			   this->numericUpDown1->Size = System::Drawing::Size(257, 26);
			   this->numericUpDown1->TabIndex = 7;
			   // 
			   // textBox1
			   // 
			   this->textBox1->Location = System::Drawing::Point(154, 219);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(257, 26);
			   this->textBox1->TabIndex = 8;
			   // 
			   // textBox2
			   // 
			   this->textBox2->Location = System::Drawing::Point(154, 297);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(257, 26);
			   this->textBox2->TabIndex = 9;
			   // 
			   // CreateForm
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(717, 448);
			   this->Controls->Add(this->textBox2);
			   this->Controls->Add(this->textBox1);
			   this->Controls->Add(this->numericUpDown1);
			   this->Controls->Add(this->listBox1);
			   this->Controls->Add(this->button1);
			   this->Controls->Add(this->label5);
			   this->Controls->Add(this->label4);
			   this->Controls->Add(this->label3);
			   this->Controls->Add(this->label2);
			   this->Controls->Add(this->label1);
			   this->Name = L"CreateForm";
			   this->Text = L"CreateForm";
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

#pragma region input
		string type = msclr::interop::marshal_as<string>(this->listBox1->SelectedItem->ToString());
		string eventID = msclr::interop::marshal_as<string>(this->numericUpDown1->Text);
		string source = msclr::interop::marshal_as<string>(this->textBox1->Text);
		string description = msclr::interop::marshal_as<string>(this->textBox2->Text);
#pragma endregion

		stringstream ss;
		ss << "EventCreate /t " << type << " /id " << eventID << " /l APPLICATION /so " << source << " /d \"" << description << "\"";
		system(ss.str().c_str());
		MessageBox::Show("Event was created");

		this->Hide();
		otherform->Show();
	}
	};
}
