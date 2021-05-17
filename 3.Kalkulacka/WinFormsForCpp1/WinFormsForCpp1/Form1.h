#pragma once

namespace WinFormsForCpp1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
		}

	protected:
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  displej;
	private: System::Windows::Forms::Button^  cis7;
	private: System::Windows::Forms::Button^  cis8;
	private: System::Windows::Forms::Button^  cis9;
	private: System::Windows::Forms::Button^  cis4;
	private: System::Windows::Forms::Button^  cis5;
	private: System::Windows::Forms::Button^  cis6;
	private: System::Windows::Forms::Button^  cis1;
	private: System::Windows::Forms::Button^  cis2;
	private: System::Windows::Forms::Button^  cis3;
	private: System::Windows::Forms::Button^  cis0;
	private: System::Windows::Forms::Button^  clear;

	private: System::Windows::Forms::Button^  rovn;
	private: System::Windows::Forms::Button^  pi;
	private: System::Windows::Forms::Button^  carka;



	private: System::Windows::Forms::Button^  plusminus;

	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::Button^  plus;
	private: System::Windows::Forms::Button^  minus;
	private: System::Windows::Forms::Button^  deleno;
	private: System::Windows::Forms::Button^  krat;




	private: System::Windows::Forms::Button^  zpet;
	private: System::Windows::Forms::Button^  round;
	private: System::Windows::Forms::Button^  mocnina;
	private: System::Windows::Forms::Button^  odmocnina;
	private: System::Windows::Forms::Button^  abs;
	private: System::Windows::Forms::Button^  prev;
	private: System::Windows::Forms::Button^  factorial;
	private: System::Windows::Forms::Button^  xnay;
	private: System::Windows::Forms::Button^ mc;
	private: System::Windows::Forms::Button^ mplus;
	private: System::Windows::Forms::Button^ mminus;
	private: System::Windows::Forms::Button^ ms;
	private: System::Windows::Forms::Button^ sin;
	private: System::Windows::Forms::Button^ yomdx;







	private: System::Windows::Forms::Button^ cotg;

	private: System::Windows::Forms::Button^ tg;

	private: System::Windows::Forms::Button^ cos;

	private: System::Windows::Forms::RadioButton^ deg;
	private: System::Windows::Forms::RadioButton^ rad;
	private: System::Windows::Forms::Button^ mr;


	private: System::ComponentModel::IContainer^ components;
	protected:


	private:


#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->displej = (gcnew System::Windows::Forms::TextBox());
			this->cis7 = (gcnew System::Windows::Forms::Button());
			this->cis8 = (gcnew System::Windows::Forms::Button());
			this->cis9 = (gcnew System::Windows::Forms::Button());
			this->cis4 = (gcnew System::Windows::Forms::Button());
			this->cis5 = (gcnew System::Windows::Forms::Button());
			this->cis6 = (gcnew System::Windows::Forms::Button());
			this->cis1 = (gcnew System::Windows::Forms::Button());
			this->cis2 = (gcnew System::Windows::Forms::Button());
			this->cis3 = (gcnew System::Windows::Forms::Button());
			this->cis0 = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->rovn = (gcnew System::Windows::Forms::Button());
			this->pi = (gcnew System::Windows::Forms::Button());
			this->carka = (gcnew System::Windows::Forms::Button());
			this->plusminus = (gcnew System::Windows::Forms::Button());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->plus = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->deleno = (gcnew System::Windows::Forms::Button());
			this->krat = (gcnew System::Windows::Forms::Button());
			this->zpet = (gcnew System::Windows::Forms::Button());
			this->round = (gcnew System::Windows::Forms::Button());
			this->mocnina = (gcnew System::Windows::Forms::Button());
			this->odmocnina = (gcnew System::Windows::Forms::Button());
			this->abs = (gcnew System::Windows::Forms::Button());
			this->prev = (gcnew System::Windows::Forms::Button());
			this->factorial = (gcnew System::Windows::Forms::Button());
			this->xnay = (gcnew System::Windows::Forms::Button());
			this->mc = (gcnew System::Windows::Forms::Button());
			this->mplus = (gcnew System::Windows::Forms::Button());
			this->mminus = (gcnew System::Windows::Forms::Button());
			this->ms = (gcnew System::Windows::Forms::Button());
			this->sin = (gcnew System::Windows::Forms::Button());
			this->yomdx = (gcnew System::Windows::Forms::Button());
			this->cotg = (gcnew System::Windows::Forms::Button());
			this->tg = (gcnew System::Windows::Forms::Button());
			this->cos = (gcnew System::Windows::Forms::Button());
			this->deg = (gcnew System::Windows::Forms::RadioButton());
			this->rad = (gcnew System::Windows::Forms::RadioButton());
			this->mr = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// displej
			// 
			this->displej->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->displej->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->displej->ForeColor = System::Drawing::Color::White;
			this->displej->Location = System::Drawing::Point(34, 22);
			this->displej->Margin = System::Windows::Forms::Padding(6);
			this->displej->Name = L"displej";
			this->displej->Size = System::Drawing::Size(890, 44);
			this->displej->TabIndex = 0;
			this->displej->Text = L"0";
			this->displej->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->displej->TextChanged += gcnew System::EventHandler(this, &Form1::displej_TextChanged);
			// 
			// cis7
			// 
			this->cis7->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis7->Cursor = System::Windows::Forms::Cursors::Default;
			this->cis7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis7->ForeColor = System::Drawing::Color::White;
			this->cis7->Location = System::Drawing::Point(488, 166);
			this->cis7->Margin = System::Windows::Forms::Padding(6);
			this->cis7->Name = L"cis7";
			this->cis7->Size = System::Drawing::Size(100, 74);
			this->cis7->TabIndex = 1;
			this->cis7->Text = L"7";
			this->cis7->UseVisualStyleBackColor = false;
			this->cis7->Click += gcnew System::EventHandler(this, &Form1::cis7_Click);
			// 
			// cis8
			// 
			this->cis8->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis8->ForeColor = System::Drawing::Color::White;
			this->cis8->Location = System::Drawing::Point(600, 166);
			this->cis8->Margin = System::Windows::Forms::Padding(6);
			this->cis8->Name = L"cis8";
			this->cis8->Size = System::Drawing::Size(100, 74);
			this->cis8->TabIndex = 2;
			this->cis8->Text = L"8";
			this->cis8->UseVisualStyleBackColor = false;
			this->cis8->Click += gcnew System::EventHandler(this, &Form1::cis8_Click);
			// 
			// cis9
			// 
			this->cis9->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis9->ForeColor = System::Drawing::Color::White;
			this->cis9->Location = System::Drawing::Point(712, 166);
			this->cis9->Margin = System::Windows::Forms::Padding(6);
			this->cis9->Name = L"cis9";
			this->cis9->Size = System::Drawing::Size(100, 74);
			this->cis9->TabIndex = 3;
			this->cis9->Text = L"9";
			this->cis9->UseVisualStyleBackColor = false;
			this->cis9->Click += gcnew System::EventHandler(this, &Form1::cis9_Click);
			// 
			// cis4
			// 
			this->cis4->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis4->ForeColor = System::Drawing::Color::White;
			this->cis4->Location = System::Drawing::Point(488, 250);
			this->cis4->Margin = System::Windows::Forms::Padding(6);
			this->cis4->Name = L"cis4";
			this->cis4->Size = System::Drawing::Size(100, 74);
			this->cis4->TabIndex = 4;
			this->cis4->Text = L"4";
			this->cis4->UseVisualStyleBackColor = false;
			this->cis4->Click += gcnew System::EventHandler(this, &Form1::cis4_Click);
			// 
			// cis5
			// 
			this->cis5->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis5->ForeColor = System::Drawing::Color::White;
			this->cis5->Location = System::Drawing::Point(600, 250);
			this->cis5->Margin = System::Windows::Forms::Padding(6);
			this->cis5->Name = L"cis5";
			this->cis5->Size = System::Drawing::Size(100, 74);
			this->cis5->TabIndex = 5;
			this->cis5->Text = L"5";
			this->cis5->UseVisualStyleBackColor = false;
			this->cis5->Click += gcnew System::EventHandler(this, &Form1::cis5_Click);
			// 
			// cis6
			// 
			this->cis6->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis6->ForeColor = System::Drawing::Color::White;
			this->cis6->Location = System::Drawing::Point(712, 250);
			this->cis6->Margin = System::Windows::Forms::Padding(6);
			this->cis6->Name = L"cis6";
			this->cis6->Size = System::Drawing::Size(100, 74);
			this->cis6->TabIndex = 6;
			this->cis6->Text = L"6";
			this->cis6->UseVisualStyleBackColor = false;
			this->cis6->Click += gcnew System::EventHandler(this, &Form1::cis6_Click);
			// 
			// cis1
			// 
			this->cis1->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis1->ForeColor = System::Drawing::Color::White;
			this->cis1->Location = System::Drawing::Point(488, 342);
			this->cis1->Margin = System::Windows::Forms::Padding(6);
			this->cis1->Name = L"cis1";
			this->cis1->Size = System::Drawing::Size(100, 74);
			this->cis1->TabIndex = 7;
			this->cis1->Text = L"1";
			this->cis1->UseVisualStyleBackColor = false;
			this->cis1->Click += gcnew System::EventHandler(this, &Form1::cis1_Click);
			// 
			// cis2
			// 
			this->cis2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis2->ForeColor = System::Drawing::Color::White;
			this->cis2->Location = System::Drawing::Point(600, 342);
			this->cis2->Margin = System::Windows::Forms::Padding(6);
			this->cis2->Name = L"cis2";
			this->cis2->Size = System::Drawing::Size(100, 74);
			this->cis2->TabIndex = 8;
			this->cis2->Text = L"2";
			this->cis2->UseVisualStyleBackColor = false;
			this->cis2->Click += gcnew System::EventHandler(this, &Form1::cis2_Click);
			// 
			// cis3
			// 
			this->cis3->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis3->ForeColor = System::Drawing::Color::White;
			this->cis3->Location = System::Drawing::Point(712, 342);
			this->cis3->Margin = System::Windows::Forms::Padding(6);
			this->cis3->Name = L"cis3";
			this->cis3->Size = System::Drawing::Size(100, 74);
			this->cis3->TabIndex = 9;
			this->cis3->Text = L"3";
			this->cis3->UseVisualStyleBackColor = false;
			this->cis3->Click += gcnew System::EventHandler(this, &Form1::cis3_Click);
			// 
			// cis0
			// 
			this->cis0->BackColor = System::Drawing::SystemColors::ControlDark;
			this->cis0->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cis0->ForeColor = System::Drawing::Color::White;
			this->cis0->Location = System::Drawing::Point(488, 428);
			this->cis0->Margin = System::Windows::Forms::Padding(6);
			this->cis0->Name = L"cis0";
			this->cis0->Size = System::Drawing::Size(212, 74);
			this->cis0->TabIndex = 10;
			this->cis0->Text = L"0";
			this->cis0->UseVisualStyleBackColor = false;
			this->cis0->Click += gcnew System::EventHandler(this, &Form1::cis0_Click);
			// 
			// clear
			// 
			this->clear->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->clear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->clear->ForeColor = System::Drawing::Color::White;
			this->clear->Location = System::Drawing::Point(488, 80);
			this->clear->Margin = System::Windows::Forms::Padding(6);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(100, 74);
			this->clear->TabIndex = 11;
			this->clear->Text = L"CE";
			this->clear->UseVisualStyleBackColor = false;
			this->clear->Click += gcnew System::EventHandler(this, &Form1::clear_Click);
			// 
			// rovn
			// 
			this->rovn->BackColor = System::Drawing::Color::DarkOrange;
			this->rovn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->rovn->ForeColor = System::Drawing::Color::WhiteSmoke;
			this->rovn->Location = System::Drawing::Point(712, 428);
			this->rovn->Margin = System::Windows::Forms::Padding(6);
			this->rovn->Name = L"rovn";
			this->rovn->Size = System::Drawing::Size(212, 74);
			this->rovn->TabIndex = 12;
			this->rovn->Text = L"=";
			this->rovn->UseVisualStyleBackColor = false;
			this->rovn->Click += gcnew System::EventHandler(this, &Form1::rovn_Click);
			// 
			// pi
			// 
			this->pi->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->pi->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->pi->ForeColor = System::Drawing::Color::White;
			this->pi->Location = System::Drawing::Point(376, 168);
			this->pi->Margin = System::Windows::Forms::Padding(6);
			this->pi->Name = L"pi";
			this->pi->Size = System::Drawing::Size(100, 74);
			this->pi->TabIndex = 14;
			this->pi->Text = L"π";
			this->pi->UseVisualStyleBackColor = false;
			this->pi->Click += gcnew System::EventHandler(this, &Form1::pi_Click);
			// 
			// carka
			// 
			this->carka->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->carka->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->carka->ForeColor = System::Drawing::Color::White;
			this->carka->Location = System::Drawing::Point(376, 428);
			this->carka->Margin = System::Windows::Forms::Padding(6);
			this->carka->Name = L"carka";
			this->carka->Size = System::Drawing::Size(100, 74);
			this->carka->TabIndex = 15;
			this->carka->Text = L",";
			this->carka->UseVisualStyleBackColor = false;
			this->carka->Click += gcnew System::EventHandler(this, &Form1::carka_Click);
			// 
			// plusminus
			// 
			this->plusminus->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->plusminus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->plusminus->ForeColor = System::Drawing::Color::White;
			this->plusminus->Location = System::Drawing::Point(600, 80);
			this->plusminus->Margin = System::Windows::Forms::Padding(6);
			this->plusminus->Name = L"plusminus";
			this->plusminus->Size = System::Drawing::Size(100, 74);
			this->plusminus->TabIndex = 16;
			this->plusminus->Text = L"±";
			this->plusminus->UseVisualStyleBackColor = false;
			this->plusminus->Click += gcnew System::EventHandler(this, &Form1::plusminus_Click);
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(32, 32);
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(61, 4);
			// 
			// plus
			// 
			this->plus->BackColor = System::Drawing::Color::DarkOrange;
			this->plus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->plus->ForeColor = System::Drawing::Color::White;
			this->plus->Location = System::Drawing::Point(824, 342);
			this->plus->Margin = System::Windows::Forms::Padding(6);
			this->plus->Name = L"plus";
			this->plus->Size = System::Drawing::Size(100, 74);
			this->plus->TabIndex = 17;
			this->plus->Text = L"+";
			this->plus->UseVisualStyleBackColor = false;
			this->plus->Click += gcnew System::EventHandler(this, &Form1::plus_Click);
			// 
			// minus
			// 
			this->minus->BackColor = System::Drawing::Color::DarkOrange;
			this->minus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->minus->ForeColor = System::Drawing::Color::White;
			this->minus->Location = System::Drawing::Point(824, 250);
			this->minus->Margin = System::Windows::Forms::Padding(6);
			this->minus->Name = L"minus";
			this->minus->Size = System::Drawing::Size(100, 74);
			this->minus->TabIndex = 18;
			this->minus->Text = L"-";
			this->minus->UseVisualStyleBackColor = false;
			this->minus->Click += gcnew System::EventHandler(this, &Form1::minus_Click);
			// 
			// deleno
			// 
			this->deleno->BackColor = System::Drawing::Color::DarkOrange;
			this->deleno->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->deleno->ForeColor = System::Drawing::Color::White;
			this->deleno->Location = System::Drawing::Point(824, 80);
			this->deleno->Margin = System::Windows::Forms::Padding(6);
			this->deleno->Name = L"deleno";
			this->deleno->Size = System::Drawing::Size(100, 74);
			this->deleno->TabIndex = 19;
			this->deleno->Text = L"÷";
			this->deleno->UseVisualStyleBackColor = false;
			this->deleno->Click += gcnew System::EventHandler(this, &Form1::deleno_Click);
			// 
			// krat
			// 
			this->krat->BackColor = System::Drawing::Color::DarkOrange;
			this->krat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->krat->ForeColor = System::Drawing::Color::White;
			this->krat->Location = System::Drawing::Point(824, 166);
			this->krat->Margin = System::Windows::Forms::Padding(6);
			this->krat->Name = L"krat";
			this->krat->Size = System::Drawing::Size(100, 74);
			this->krat->TabIndex = 20;
			this->krat->Text = L"×";
			this->krat->UseVisualStyleBackColor = false;
			this->krat->Click += gcnew System::EventHandler(this, &Form1::krat_Click);
			// 
			// zpet
			// 
			this->zpet->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->zpet->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->zpet->ForeColor = System::Drawing::Color::White;
			this->zpet->Location = System::Drawing::Point(712, 80);
			this->zpet->Margin = System::Windows::Forms::Padding(6);
			this->zpet->Name = L"zpet";
			this->zpet->Size = System::Drawing::Size(100, 74);
			this->zpet->TabIndex = 21;
			this->zpet->Text = L"«";
			this->zpet->UseVisualStyleBackColor = false;
			this->zpet->Click += gcnew System::EventHandler(this, &Form1::zpet_Click);
			// 
			// round
			// 
			this->round->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->round->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->round->ForeColor = System::Drawing::Color::White;
			this->round->Location = System::Drawing::Point(376, 254);
			this->round->Margin = System::Windows::Forms::Padding(6);
			this->round->Name = L"round";
			this->round->Size = System::Drawing::Size(100, 74);
			this->round->TabIndex = 22;
			this->round->Text = L"round";
			this->round->UseVisualStyleBackColor = false;
			this->round->Click += gcnew System::EventHandler(this, &Form1::round_Click);
			// 
			// mocnina
			// 
			this->mocnina->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->mocnina->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mocnina->ForeColor = System::Drawing::Color::White;
			this->mocnina->Location = System::Drawing::Point(264, 78);
			this->mocnina->Margin = System::Windows::Forms::Padding(6);
			this->mocnina->Name = L"mocnina";
			this->mocnina->Size = System::Drawing::Size(100, 74);
			this->mocnina->TabIndex = 23;
			this->mocnina->Text = L"x²";
			this->mocnina->UseVisualStyleBackColor = false;
			this->mocnina->Click += gcnew System::EventHandler(this, &Form1::mocnina_Click);
			// 
			// odmocnina
			// 
			this->odmocnina->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->odmocnina->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->odmocnina->ForeColor = System::Drawing::Color::White;
			this->odmocnina->Location = System::Drawing::Point(264, 340);
			this->odmocnina->Margin = System::Windows::Forms::Padding(6);
			this->odmocnina->Name = L"odmocnina";
			this->odmocnina->Size = System::Drawing::Size(100, 74);
			this->odmocnina->TabIndex = 24;
			this->odmocnina->Text = L"√";
			this->odmocnina->UseVisualStyleBackColor = false;
			this->odmocnina->Click += gcnew System::EventHandler(this, &Form1::odmocnina_Click);
			// 
			// abs
			// 
			this->abs->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->abs->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->abs->ForeColor = System::Drawing::Color::White;
			this->abs->Location = System::Drawing::Point(376, 344);
			this->abs->Margin = System::Windows::Forms::Padding(6);
			this->abs->Name = L"abs";
			this->abs->Size = System::Drawing::Size(100, 74);
			this->abs->TabIndex = 25;
			this->abs->Text = L"abs";
			this->abs->UseVisualStyleBackColor = false;
			this->abs->Click += gcnew System::EventHandler(this, &Form1::abs_Click);
			// 
			// prev
			// 
			this->prev->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->prev->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->prev->ForeColor = System::Drawing::Color::White;
			this->prev->Location = System::Drawing::Point(264, 248);
			this->prev->Margin = System::Windows::Forms::Padding(6);
			this->prev->Name = L"prev";
			this->prev->Size = System::Drawing::Size(100, 74);
			this->prev->TabIndex = 26;
			this->prev->Text = L"1/x";
			this->prev->UseVisualStyleBackColor = false;
			this->prev->Click += gcnew System::EventHandler(this, &Form1::prev_Click);
			// 
			// factorial
			// 
			this->factorial->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->factorial->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->factorial->ForeColor = System::Drawing::Color::White;
			this->factorial->Location = System::Drawing::Point(376, 82);
			this->factorial->Margin = System::Windows::Forms::Padding(6);
			this->factorial->Name = L"factorial";
			this->factorial->Size = System::Drawing::Size(100, 74);
			this->factorial->TabIndex = 27;
			this->factorial->Text = L"x!";
			this->factorial->UseVisualStyleBackColor = false;
			this->factorial->Click += gcnew System::EventHandler(this, &Form1::factorial_Click);
			// 
			// xnay
			// 
			this->xnay->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->xnay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->xnay->ForeColor = System::Drawing::Color::White;
			this->xnay->Location = System::Drawing::Point(264, 164);
			this->xnay->Margin = System::Windows::Forms::Padding(6);
			this->xnay->Name = L"xnay";
			this->xnay->Size = System::Drawing::Size(100, 74);
			this->xnay->TabIndex = 28;
			this->xnay->Text = L"x^y";
			this->xnay->UseVisualStyleBackColor = false;
			this->xnay->Click += gcnew System::EventHandler(this, &Form1::xnay_Click);
			// 
			// mc
			// 
			this->mc->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->mc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mc->ForeColor = System::Drawing::Color::White;
			this->mc->Location = System::Drawing::Point(42, 426);
			this->mc->Margin = System::Windows::Forms::Padding(6);
			this->mc->Name = L"mc";
			this->mc->Size = System::Drawing::Size(100, 74);
			this->mc->TabIndex = 29;
			this->mc->Text = L"mc";
			this->mc->UseVisualStyleBackColor = false;
			this->mc->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// mplus
			// 
			this->mplus->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->mplus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mplus->ForeColor = System::Drawing::Color::White;
			this->mplus->Location = System::Drawing::Point(42, 164);
			this->mplus->Margin = System::Windows::Forms::Padding(6);
			this->mplus->Name = L"mplus";
			this->mplus->Size = System::Drawing::Size(100, 74);
			this->mplus->TabIndex = 30;
			this->mplus->Text = L"m+";
			this->mplus->UseVisualStyleBackColor = false;
			this->mplus->Click += gcnew System::EventHandler(this, &Form1::mplus_Click);
			// 
			// mminus
			// 
			this->mminus->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->mminus->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mminus->ForeColor = System::Drawing::Color::White;
			this->mminus->Location = System::Drawing::Point(42, 250);
			this->mminus->Margin = System::Windows::Forms::Padding(6);
			this->mminus->Name = L"mminus";
			this->mminus->Size = System::Drawing::Size(100, 74);
			this->mminus->TabIndex = 31;
			this->mminus->Text = L"m-";
			this->mminus->UseVisualStyleBackColor = false;
			this->mminus->Click += gcnew System::EventHandler(this, &Form1::mminus_Click);
			// 
			// ms
			// 
			this->ms->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ms->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->ms->ForeColor = System::Drawing::Color::White;
			this->ms->Location = System::Drawing::Point(42, 82);
			this->ms->Margin = System::Windows::Forms::Padding(6);
			this->ms->Name = L"ms";
			this->ms->Size = System::Drawing::Size(100, 74);
			this->ms->TabIndex = 32;
			this->ms->Text = L"ms";
			this->ms->UseVisualStyleBackColor = false;
			this->ms->Click += gcnew System::EventHandler(this, &Form1::ms_Click);
			// 
			// sin
			// 
			this->sin->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->sin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->sin->ForeColor = System::Drawing::Color::White;
			this->sin->Location = System::Drawing::Point(154, 164);
			this->sin->Margin = System::Windows::Forms::Padding(6);
			this->sin->Name = L"sin";
			this->sin->Size = System::Drawing::Size(100, 74);
			this->sin->TabIndex = 33;
			this->sin->Text = L"sin";
			this->sin->UseVisualStyleBackColor = false;
			this->sin->Click += gcnew System::EventHandler(this, &Form1::sin_Click);
			// 
			// yomdx
			// 
			this->yomdx->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->yomdx->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->yomdx->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->yomdx->ForeColor = System::Drawing::Color::White;
			this->yomdx->Location = System::Drawing::Point(264, 426);
			this->yomdx->Margin = System::Windows::Forms::Padding(6);
			this->yomdx->Name = L"yomdx";
			this->yomdx->Size = System::Drawing::Size(100, 74);
			this->yomdx->TabIndex = 37;
			this->yomdx->Text = L"y√x";
			this->yomdx->UseVisualStyleBackColor = false;
			this->yomdx->Click += gcnew System::EventHandler(this, &Form1::yomdx_Click);
			// 
			// cotg
			// 
			this->cotg->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->cotg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cotg->ForeColor = System::Drawing::Color::White;
			this->cotg->Location = System::Drawing::Point(154, 426);
			this->cotg->Margin = System::Windows::Forms::Padding(6);
			this->cotg->Name = L"cotg";
			this->cotg->Size = System::Drawing::Size(100, 74);
			this->cotg->TabIndex = 36;
			this->cotg->Text = L"cotg";
			this->cotg->UseVisualStyleBackColor = false;
			this->cotg->Click += gcnew System::EventHandler(this, &Form1::cotg_Click);
			// 
			// tg
			// 
			this->tg->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->tg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->tg->ForeColor = System::Drawing::Color::White;
			this->tg->Location = System::Drawing::Point(154, 340);
			this->tg->Margin = System::Windows::Forms::Padding(6);
			this->tg->Name = L"tg";
			this->tg->Size = System::Drawing::Size(100, 74);
			this->tg->TabIndex = 35;
			this->tg->Text = L"tg";
			this->tg->UseVisualStyleBackColor = false;
			this->tg->Click += gcnew System::EventHandler(this, &Form1::tg_Click);
			// 
			// cos
			// 
			this->cos->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->cos->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->cos->ForeColor = System::Drawing::Color::White;
			this->cos->Location = System::Drawing::Point(154, 250);
			this->cos->Margin = System::Windows::Forms::Padding(6);
			this->cos->Name = L"cos";
			this->cos->Size = System::Drawing::Size(100, 74);
			this->cos->TabIndex = 34;
			this->cos->Text = L"cos";
			this->cos->UseVisualStyleBackColor = false;
			this->cos->Click += gcnew System::EventHandler(this, &Form1::cos_Click);
			// 
			// deg
			// 
			this->deg->AutoSize = true;
			this->deg->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->deg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->deg->ForeColor = System::Drawing::Color::White;
			this->deg->Location = System::Drawing::Point(163, 82);
			this->deg->Margin = System::Windows::Forms::Padding(6);
			this->deg->Name = L"deg";
			this->deg->Size = System::Drawing::Size(90, 35);
			this->deg->TabIndex = 38;
			this->deg->TabStop = true;
			this->deg->Text = L"deg";
			this->deg->UseVisualStyleBackColor = false;
			this->deg->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// rad
			// 
			this->rad->AutoSize = true;
			this->rad->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->rad->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->rad->ForeColor = System::Drawing::Color::White;
			this->rad->Location = System::Drawing::Point(163, 121);
			this->rad->Margin = System::Windows::Forms::Padding(6);
			this->rad->Name = L"rad";
			this->rad->Size = System::Drawing::Size(84, 35);
			this->rad->TabIndex = 39;
			this->rad->TabStop = true;
			this->rad->Text = L"rad";
			this->rad->UseVisualStyleBackColor = false;
			this->rad->CheckedChanged += gcnew System::EventHandler(this, &Form1::rad_CheckedChanged);
			// 
			// mr
			// 
			this->mr->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->mr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(238)));
			this->mr->ForeColor = System::Drawing::Color::White;
			this->mr->Location = System::Drawing::Point(42, 344);
			this->mr->Margin = System::Windows::Forms::Padding(6);
			this->mr->Name = L"mr";
			this->mr->Size = System::Drawing::Size(100, 74);
			this->mr->TabIndex = 40;
			this->mr->Text = L"mr";
			this->mr->UseVisualStyleBackColor = false;
			this->mr->Click += gcnew System::EventHandler(this, &Form1::mr_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->ClientSize = System::Drawing::Size(980, 558);
			this->Controls->Add(this->mr);
			this->Controls->Add(this->rad);
			this->Controls->Add(this->deg);
			this->Controls->Add(this->yomdx);
			this->Controls->Add(this->cotg);
			this->Controls->Add(this->tg);
			this->Controls->Add(this->cos);
			this->Controls->Add(this->sin);
			this->Controls->Add(this->ms);
			this->Controls->Add(this->mminus);
			this->Controls->Add(this->mplus);
			this->Controls->Add(this->mc);
			this->Controls->Add(this->xnay);
			this->Controls->Add(this->factorial);
			this->Controls->Add(this->prev);
			this->Controls->Add(this->abs);
			this->Controls->Add(this->odmocnina);
			this->Controls->Add(this->mocnina);
			this->Controls->Add(this->round);
			this->Controls->Add(this->zpet);
			this->Controls->Add(this->krat);
			this->Controls->Add(this->deleno);
			this->Controls->Add(this->minus);
			this->Controls->Add(this->plus);
			this->Controls->Add(this->plusminus);
			this->Controls->Add(this->carka);
			this->Controls->Add(this->pi);
			this->Controls->Add(this->rovn);
			this->Controls->Add(this->clear);
			this->Controls->Add(this->cis0);
			this->Controls->Add(this->cis3);
			this->Controls->Add(this->cis2);
			this->Controls->Add(this->cis1);
			this->Controls->Add(this->cis6);
			this->Controls->Add(this->cis5);
			this->Controls->Add(this->cis4);
			this->Controls->Add(this->cis9);
			this->Controls->Add(this->cis8);
			this->Controls->Add(this->cis7);
			this->Controls->Add(this->displej);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(6);
			this->Name = L"Form1";
			this->Text = L"Tajná myška věc";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		double prvni, druhe, vys,mem;
		int op; // 1+, 2-, 3*, 4/, 5x^y, 6yodmx
		int tmp = 0,hlp=0;
		static int stup=0;
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void cis7_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "7";
		else
			displej->Text += "7";
	}
	private: System::Void cis8_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "8";
		else
			displej->Text += "8";
	}
	private: System::Void cis9_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "9";
		else
			displej->Text += "9";
	}
	private: System::Void cis4_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "4";
		else
			displej->Text += "4";
	}
	private: System::Void cis5_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "5";
		else
			displej->Text += "5";
	}
	private: System::Void cis6_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "6";
		else
			displej->Text += "6";
	}
	private: System::Void cis1_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "1";
		else
			displej->Text += "1";
	}
	private: System::Void cis2_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "2";
		else
			displej->Text += "2";
	}
	private: System::Void cis3_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "3";
		else
			displej->Text += "3";
	}
	private: System::Void cis0_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text == "0")
			displej->Text = "0";
		else
			displej->Text += "0";
	}
	private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e) {
		displej->Text = "0";
	}
	private: System::Void plusminus_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		vys = -prvni;
		displej->Text = System::Convert::ToString(vys);
	}
	private: System::Void pi_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Math::PI;
		displej->Text = System::Convert::ToString(prvni);
	}
	private: System::Void carka_Click(System::Object^  sender, System::EventArgs^  e) {
		if (displej->Text->Contains(",") == false)
			displej->Text += ",";
		else
		{
			MessageBox::Show("Nelze mit dve carky");
		}
	}
	private: System::Void zpet_Click(System::Object^  sender, System::EventArgs^  e) {
		int p;
		p = displej->Text->Length;
		if (p == 0|| p==1)
		{
			displej->Text = "0";
		}
		else{
			displej->Text = displej->Text->Remove(p - 1, 1);
		}
	}
	private: System::Void round_Click(System::Object^  sender, System::EventArgs^  e) {
		int p;
		prvni = System::Convert::ToDouble(displej->Text);
		prvni = System::Math::Round(prvni);
		displej->Text = System::Convert::ToString(prvni);
	}
	private: System::Void mocnina_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		prvni = System::Math::Pow(prvni, 2);
		displej->Text = System::Convert::ToString(prvni);
	}
	private: System::Void odmocnina_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		prvni = System::Math::Sqrt(prvni);
		displej->Text = System::Convert::ToString(prvni);
	}
	private: System::Void abs_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		prvni = System::Math::Abs(prvni);
		displej->Text = System::Convert::ToString(prvni);
	}
	private: System::Void factorial_Click(System::Object^  sender, System::EventArgs^  e) {
		vys = 0;
		prvni = System::Convert::ToDouble(displej->Text);
		if (prvni < 0.0 || displej->Text->Contains(",") == false) MessageBox::Show("Nelze udelat faktorial");
		else if (prvni > 0)for (; prvni > 0; prvni--) vys = prvni * vys;
		else if (prvni == 0) vys = 1;
		displej->Text = System::Convert::ToString(vys);
	}
	private: System::Void plus_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		displej->Text = "0";
		op = 1;
	}
	private: System::Void displej_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		int p;
		double a;

		p = displej->Text->Length;
		if (!double::TryParse(displej->Text, a))
		{
			MessageBox::Show("Neni cislo");
			if (p == 0 || p == 1)
			{
				displej->Text = "0";
			}
			else {
				displej->Text = displej->Text->Remove(p - 1, 1);
			}
			displej->Select(); // to Set Focus
			displej->Select(displej->Text->Length, 0); //to set cursor at the end of textbox
		}
	}
	private: System::Void rovn_Click(System::Object^  sender, System::EventArgs^  e) {
		int i; 
		druhe = System::Convert::ToDouble(displej->Text);
		switch (op)
		{
		case 1:
			vys = prvni + druhe;
			break;
		case 2:
			vys = prvni - druhe;
			break;
		case 3:
			vys = prvni * druhe;
			break;
		case 4:
			if (druhe != 0)
				vys = prvni / druhe;
			else
			{
				displej->Text = "Nelze delit 0";
				tmp = 1;
			}
			break;
		case 5:
			vys = Math::Pow(prvni, druhe);
			break;
		case 6:
			vys = System::Math::Pow(prvni, ((double)1.0 / druhe));
			break;
		}
		if(tmp == 0)
			displej->Text = System::Convert::ToString(vys);
		prvni = vys;
		druhe = 0;
	}
	private: System::Void minus_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		displej->Text = "0";
		op = 2;
	}
	private: System::Void krat_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		displej->Text = "0";
		op = 3;
	}
	private: System::Void deleno_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		displej->Text = "0";
		op = 4;
	}
	private: System::Void xnay_Click(System::Object^  sender, System::EventArgs^  e) {
		prvni = System::Convert::ToDouble(displej->Text);
		displej->Text = "0";
		op = 5;
	}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	mem = 0;
	hlp = 0;
	displej->Text = "0";
}
private: System::Void mplus_Click(System::Object^ sender, System::EventArgs^ e) {
	if (hlp == 1) {
		prvni = System::Convert::ToDouble(displej->Text);
		mem += prvni;
	}
	displej->Text = "0";
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (true) stup== 0;
}
private: System::Void rad_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (true) stup == 1;
}
private: System::Void sin_Click(System::Object^ sender, System::EventArgs^ e) {
	prvni = System::Convert::ToDouble(displej->Text);
	if (stup == 0) prvni = (prvni * Math::PI) / 180;
	prvni = Math::Sin(prvni);
	displej->Text = Convert::ToString(prvni);
}

private: System::Void cos_Click(System::Object^ sender, System::EventArgs^ e) {
	prvni = System::Convert::ToDouble(displej->Text);
	if (stup == 0) prvni = (prvni * Math::PI) / 180;
	prvni = Math::Cos(prvni);
	displej->Text = Convert::ToString(prvni);
}
private: System::Void tg_Click(System::Object^ sender, System::EventArgs^ e) {
	prvni = System::Convert::ToDouble(displej->Text);
	if (stup == 0) prvni = (prvni * Math::PI) / 180;
	prvni = Math::Tan(prvni);
	displej->Text = Convert::ToString(prvni);
}
private: System::Void cotg_Click(System::Object^ sender, System::EventArgs^ e) {
	prvni = System::Convert::ToDouble(displej->Text);
	if (stup == 0) prvni = (prvni * Math::PI) / 180;
	prvni = Math::Tan(prvni);
	prvni = 1 / prvni;
	displej->Text = Convert::ToString(prvni);
}
private: System::Void yomdx_Click(System::Object^ sender, System::EventArgs^ e) {
	prvni = System::Convert::ToDouble(displej->Text);
	displej->Text = "0";
	op = 6;
}
	private: System::Void prev_Click(System::Object^ sender, System::EventArgs^ e) {
		prvni = System::Convert::ToDouble(displej->Text);
		prvni = 1 / prvni;
		displej->Text = Convert::ToString(prvni);
}
private: System::Void mr_Click(System::Object^ sender, System::EventArgs^ e) {
	displej->Text = Convert::ToString(mem);
}
private: System::Void mminus_Click(System::Object^ sender, System::EventArgs^ e) {
	if (hlp == 1)
	{
		prvni = System::Convert::ToDouble(displej->Text);
		mem -= prvni;
	}
		displej->Text = "0";
}
	private: System::Void ms_Click(System::Object^ sender, System::EventArgs^ e) {
	if (mem == 0) {
		prvni = System::Convert::ToDouble(displej->Text);
		mem = prvni;
		hlp = 1;
	}
	displej->Text = "0";
}
private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
