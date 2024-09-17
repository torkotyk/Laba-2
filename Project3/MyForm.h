#pragma once

namespace Project3 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 13.875F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 52;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
				L"Лінія ", L"Прямокутник", L"Зафарбований прямокутник ",
					L"Еліпс ", L"Зафарбований еліпс", L"Сектор ", L"Зірка"
			});
			this->listBox1->Location = System::Drawing::Point(34, 31);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(515, 56);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listBox1_SelectedIndexChanged);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::AliceBlue;
			this->ClientSize = System::Drawing::Size(1034, 780);
			this->Controls->Add(this->listBox1);
			this->Name = L"MyForm";
			this->Text = L"Лабораторна робота №2-3";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		// canva
		Graphics^ graf = CreateGraphics();

		//pen
		Pen^ pn = gcnew System::Drawing::Pen(Color::DarkBlue, 4);

		//brush

		Brush^ br = gcnew System::Drawing::SolidBrush(Color::DarkBlue);

		// Clear forms
		graf->Clear(SystemColors::Control);



		switch (listBox1->SelectedIndex)
		{
		case 0:graf->DrawLine(pn, 150, 90, 360, 180);  break;
		case 1:graf->DrawRectangle(pn, 150, 90, 300, 180);  break;
		case 2:graf->FillRectangle(br, 150, 90, 300, 180);  break;
		case 3:graf->DrawEllipse(pn, 150, 90, 300, 180);  break;
		case 4:graf->FillEllipse(br, 150, 90, 300, 180);  break;
		case 5:graf->FillPie(br, 0.f, 0.f, 350.f, 350.f, static_cast<float>(00.0f), static_cast<float>(90.0f));  break; // Сектор 
			//star
		case 6:
			array<Point> ^ star = gcnew array<Point>(10);
			// Визначаємо координати точок зірки
			star[0] = Point(300, 50);  // Верхівка зірки
			star[1] = Point(340, 150); // Права верхня точка
			star[2] = Point(460, 150); // Права нижня точка
			star[3] = Point(360, 200); // Нижня права точка
			star[4] = Point(400, 300); // Нижня середина
			star[5] = Point(300, 250); // Ліва нижня точка
			star[6] = Point(200, 300); // Нижня ліва точка
			star[7] = Point(240, 200); // Ліва середина
			star[8] = Point(140, 150); // Ліва верхня точка
			star[9] = Point(260, 150); // Верхівка зірки (повертаємося до початку)
			// Заповнюємо зірку
			graf->FillPolygon(br, star);
			break;

		}
	}
	};
}
