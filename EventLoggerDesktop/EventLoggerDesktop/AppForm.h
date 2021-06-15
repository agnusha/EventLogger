#include <msclr/marshal_cppstd.h>
#include "EventLogger.h"
#include "CreateForm.h"
#include "HelpForm.h"
using namespace std;

namespace EventLoggerDesktop {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AppForm
	/// </summary>
	public ref class AppForm : public System::Windows::Forms::Form
	{
	public:
		AppForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AppForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ListBox^ listBox2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::RichTextBox^ richTextBox1;
	private: System::Windows::Forms::SaveFileDialog^ saveFileDialog1;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ textBox1;

	private: System::ComponentModel::IContainer^ components;
	protected:


	protected:

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe Script", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::DarkBlue;
			this->label2->Location = System::Drawing::Point(504, -1);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(237, 53);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Event logger";
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::Color::LavenderBlush;
			this->listBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Corbel", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 19;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"1. Show or export to file events by Channel and Period",
					L"2. Show or export to file event by Channel and Id", L"3. Add custom event", L"4. Remove event", L"5. Clear All Event Logs",
					L"6. Show help"
			});
			this->listBox1->Location = System::Drawing::Point(43, 101);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(461, 133);
			this->listBox1->TabIndex = 2;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &AppForm::listBox1_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(39, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(178, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Select the action";
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 20;
			this->listBox2->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Application", L"Security", L"Setup", L"System",
					L"ForwardedEvents"
			});
			this->listBox2->Location = System::Drawing::Point(526, 101);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(147, 104);
			this->listBox2->TabIndex = 4;
			this->listBox2->Visible = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label3->Location = System::Drawing::Point(523, 65);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 18);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Channel";
			this->label3->Visible = false;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker1->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->dateTimePicker1->Location = System::Drawing::Point(893, 101);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(297, 26);
			this->dateTimePicker1->TabIndex = 6;
			this->dateTimePicker1->Visible = false;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->CustomFormat = L"yyyy-MM-dd";
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->dateTimePicker2->Location = System::Drawing::Point(893, 177);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(297, 26);
			this->dateTimePicker2->TabIndex = 7;
			this->dateTimePicker2->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label4->Location = System::Drawing::Point(890, 65);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 18);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Period";
			this->label4->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Navy;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Location = System::Drawing::Point(526, 300);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(647, 44);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Submit";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &AppForm::button1_Click);
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(705, 101);
			this->numericUpDown1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100000, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(159, 26);
			this->numericUpDown1->TabIndex = 10;
			this->numericUpDown1->Visible = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label5->Location = System::Drawing::Point(702, 65);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(28, 18);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Id";
			this->label5->Visible = false;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->checkBox1->Location = System::Drawing::Point(526, 248);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(174, 22);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Export to file";
			this->checkBox1->UseVisualStyleBackColor = true;
			this->checkBox1->Visible = false;
			// 
			// errorProvider1
			// 
			this->errorProvider1->ContainerControl = this;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label6->Location = System::Drawing::Point(40, 252);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(68, 18);
			this->label6->TabIndex = 13;
			this->label6->Text = L"Result";
			this->label6->Visible = false;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(42, 284);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(431, 181);
			this->richTextBox1->TabIndex = 14;
			this->richTextBox1->Text = L"Result";
			this->richTextBox1->Visible = false;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"MS Gothic", 9, System::Drawing::FontStyle::Bold));
			this->label7->Location = System::Drawing::Point(702, 146);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(68, 18);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Source";
			this->label7->Visible = false;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(705, 179);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 26);
			this->textBox1->TabIndex = 17;
			this->textBox1->Visible = false;
			// 
			// AppForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::LavenderBlush;
			this->ClientSize = System::Drawing::Size(1277, 573);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->checkBox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->label2);
			this->Name = L"AppForm";
			this->Text = L"Event logger";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region helpers
	private: Void saveDialog_Save() {
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = "Text file (*.txt)|*.txt";
		saveFileDialog1->Title = "Save a text file";
		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			IO::File::WriteAllText(saveFileDialog1->FileName, this->richTextBox1->Text);
		}
		else
		{
			MessageBox::Show("Please select file");
		}
	}
#pragma endregion

	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		this->errorProvider1->Clear();
		if (this->listBox1->SelectedIndex == 0)
		{
			this->label3->Visible = true;
			this->label4->Visible = true;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = true;
			this->dateTimePicker1->Visible = true;
			this->dateTimePicker2->Visible = true;
			this->numericUpDown1->Visible = false;
			this->checkBox1->Visible = true;
			this->textBox1->Visible = false;
			this->button1->Visible = true;
		}
		else if (this->listBox1->SelectedIndex == 1)
		{
			this->label3->Visible = true;
			this->label4->Visible = false;
			this->label5->Visible = true;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = true;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker2->Visible = false;
			this->numericUpDown1->Visible = true;
			this->checkBox1->Visible = true;
			this->textBox1->Visible = false;
			this->button1->Visible = true;
		}
		else if (this->listBox1->SelectedIndex == 2)
		{
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = false;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker2->Visible = false;
			this->numericUpDown1->Visible = false;
			this->checkBox1->Visible = false;
			this->textBox1->Visible = false;
			this->button1->Visible = false;

			CreateForm^ form = gcnew CreateForm(this);
			form->Show();
			this->Hide();
		}
		else if (this->listBox1->SelectedIndex == 3)
		{
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = true;
			this->label6->Visible = false;
			this->label7->Visible = true;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = false;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker2->Visible = false;
			this->numericUpDown1->Visible = true;
			this->checkBox1->Visible = false;
			this->textBox1->Visible = true;
			this->button1->Visible = true;

		}
		else if (this->listBox1->SelectedIndex == 4)
		{
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = false;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker2->Visible = false;
			this->numericUpDown1->Visible = false;
			this->checkBox1->Visible = false;
			this->textBox1->Visible = false;
			this->button1->Visible = false;

			system("for /F \"tokens=*\" %1 in ('wevtutil.exe el') DO wevtutil.exe cl \"%1\"");
			MessageBox::Show("Event log was cleaned");
		}
		else if (this->listBox1->SelectedIndex == 5)
		{
			this->label3->Visible = false;
			this->label4->Visible = false;
			this->label5->Visible = false;
			this->label6->Visible = false;
			this->label7->Visible = false;
			this->richTextBox1->Visible = false;
			this->listBox2->Visible = false;
			this->dateTimePicker1->Visible = false;
			this->dateTimePicker2->Visible = false;
			this->numericUpDown1->Visible = false;
			this->checkBox1->Visible = false;
			this->textBox1->Visible = false;
			this->button1->Visible = false;

			HelpForm^ form = gcnew HelpForm(this);
			form->Show();
			this->Hide();
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		EventLogger _logger;
		if (this->listBox1->SelectedIndex == 0)
		{

#pragma region validation
			if (this->listBox2->SelectedIndex == -1) {
				this->errorProvider1->SetError(this->listBox2, "Select channel");
				return;
			}
			else {
				this->errorProvider1->Clear();
			}

#pragma endregion

#pragma region setVisible
			this->label6->Visible = true;
			this->richTextBox1->Visible = true;
#pragma endregion

#pragma region input
			string queryPath = msclr::interop::marshal_as<string>(this->listBox2->SelectedItem->ToString());
			wstring queryPathW = _logger.s2ws(queryPath);

			string startDate = msclr::interop::marshal_as<string>(this->dateTimePicker1->Text) + "T00:00:00";
			wstring startDatehW = _logger.s2ws(startDate);

			string endDate = msclr::interop::marshal_as<string>(this->dateTimePicker2->Text) + "T00:00:00";
			wstring endDateW = _logger.s2ws(endDate);
#pragma endregion

			wstring queryW = \
				L"<QueryList>" \
				L"  <Query Path='Application'>" \
				L"    <Select Path='" + queryPathW + "'>" \
				L"    *[System[TimeCreated[@SystemTime&gt;='" + startDatehW + ".000Z'" \
				L"      and @SystemTime&lt;='" + endDateW + ".999Z']]]" \
				L"    </Select>" \
				L"  </Query>" \
				L"</QueryList>";
			LPCWSTR queryL = queryW.c_str();

			EVT_HANDLE hResults = EvtQuery(NULL, NULL, queryL, EvtQueryChannelPath | EvtQueryTolerateQueryErrors);
			if (NULL == hResults)
			{
				if (hResults)
					EvtClose(hResults);
			}
			if (ERROR_SUCCESS == _logger.PrintQueryStatuses(hResults))
				_logger.PrintResults(hResults);

#pragma region output
			this->richTextBox1->Text = gcnew String(_logger.get_result().c_str());
			if (this->checkBox1->Checked)
				saveDialog_Save();
#pragma endregion

			_logger.close();
		}
		else if (this->listBox1->SelectedIndex == 1)
		{
#pragma region validation
			if (this->listBox2->SelectedIndex == -1) {
				this->errorProvider1->SetError(this->listBox2, "Select channel");
				return;
			}

			if (this->numericUpDown1->Value == 0) {
				this->errorProvider1->SetError(this->numericUpDown1, "Set Id");
				return;
			}
#pragma endregion

#pragma region setVisible
			this->label6->Visible = true;
			this->richTextBox1->Visible = true;
#pragma endregion

#pragma region input
			string queryPath = msclr::interop::marshal_as<string>(this->listBox2->SelectedItem->ToString());
			wstring queryPathW = _logger.s2ws(queryPath);

			string eventID = msclr::interop::marshal_as<string>(this->numericUpDown1->Text);
			wstring eventIDhW = _logger.s2ws(eventID);
#pragma endregion

			wstring queryW = \
				L"<QueryList>" \
				L"  <Query Path='Application'>" \
				L"    <Select Path='" + queryPathW + "'>" \
				L"    Event/System[EventID=" + eventIDhW + "]" \
				L"    </Select>" \
				L"  </Query>" \
				L"</QueryList>";
			LPCWSTR queryL = queryW.c_str();

			EVT_HANDLE hResults = NULL;

			hResults = EvtQuery(NULL, NULL, queryL, EvtQueryChannelPath | EvtQueryTolerateQueryErrors);
			if (NULL == hResults)
			{
				if (hResults)
					EvtClose(hResults);
			}

			if (ERROR_SUCCESS == _logger.PrintQueryStatuses(hResults))
				_logger.PrintResults(hResults);

#pragma region output
			this->richTextBox1->Text = gcnew String(_logger.get_result().c_str());
			if (this->checkBox1->Checked)
				saveDialog_Save();
#pragma endregion

			_logger.close();

		}
		else if (this->listBox1->SelectedIndex == 3)
		{
#pragma region validation

			if (this->numericUpDown1->Value == 0) {
				this->errorProvider1->SetError(this->numericUpDown1, "Set Id");
				return;
			}

			if (this->textBox1->Text == "") {
				this->errorProvider1->SetError(this->textBox1, "Set source");
				return;
			}
#pragma endregion


#pragma region input
			string eventRecordId = msclr::interop::marshal_as<string>(this->numericUpDown1->Text);
			const char* eventRecordIdC = eventRecordId.c_str();

			string source = msclr::interop::marshal_as<string>(this->textBox1->Text->ToString()) + ".evtx";
			const char* sourceC = source.c_str();
#pragma endregion

			wchar_t ReadPath[100];
			swprintf(ReadPath, 100, L"%hs", sourceC);
			_wcslwr_s(ReadPath, wcslen(ReadPath) + 1);

			wchar_t lpEventRecordId[100];
			swprintf(lpEventRecordId, 100, L"%hs", eventRecordIdC);
			_wcslwr_s(lpEventRecordId, wcslen(lpEventRecordId) + 1);

			if (_logger.DeleteRecord(ReadPath, lpEventRecordId))
				MessageBox::Show("Delete event success.");

			_logger.close();
		}
	}
	};
}
