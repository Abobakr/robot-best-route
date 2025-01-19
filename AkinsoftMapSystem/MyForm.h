#pragma once

namespace AkinsoftMapSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

#pragma region VariableDefinitions
		Graphics^ formGraphics;
		Pen^ myPen;
		SolidBrush^ brush;
		Point drawStart;
		Point DrawEnd;
		List<Point> track;
		bool changesFound;

		int** pixels;
		int** tempPixels;
		int pixelSize;
		int widthPixelNo;
		int heightPixelNo;
		Point mazeStart;
		Point mazeEnd;
		int* a, * b;
		int** optPixels; // optimal solution
		int minLenght;
		bool firstSolFound;
		bool optSolFound;
#pragma endregion

#pragma region FormTools
	private: System::Windows::Forms::MenuStrip^ mapFindPathSystemMenuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^ actionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ clearAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setStartToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ setEndToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ findPathToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ firstFoundToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ shortestOfAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ userManualToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openMapToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveMapToolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^ enablePenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pixelSizeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ pixelSizeToolStripComboBox;
	private: System::Windows::Forms::ToolStripMenuItem^ showGridToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ penColorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^ penColortoolStripComboBox;
	private: System::Windows::Forms::ToolStripMenuItem^ enableDotToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ newClearAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
#pragma endregion

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->mapFindPathSystemMenuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->newClearAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openMapToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveMapToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->showGridToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pixelSizeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pixelSizeToolStripComboBox = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->penColorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->penColortoolStripComboBox = (gcnew System::Windows::Forms::ToolStripComboBox());
			this->actionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enableDotToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enablePenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setStartToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->setEndToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->clearAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findPathToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->firstFoundToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->shortestOfAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->userManualToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->mapFindPathSystemMenuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// mapFindPathSystemMenuStrip
			// 
			this->mapFindPathSystemMenuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->fileToolStripMenuItem,
					this->optionsToolStripMenuItem, this->actionsToolStripMenuItem, this->findPathToolStripMenuItem, this->helpToolStripMenuItem
			});
			this->mapFindPathSystemMenuStrip->Location = System::Drawing::Point(0, 0);
			this->mapFindPathSystemMenuStrip->Name = L"mapFindPathSystemMenuStrip";
			this->mapFindPathSystemMenuStrip->Size = System::Drawing::Size(399, 24);
			this->mapFindPathSystemMenuStrip->TabIndex = 0;
			this->mapFindPathSystemMenuStrip->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->newClearAllToolStripMenuItem,
					this->openMapToolStripMenuItem, this->saveAsToolStripMenuItem, this->saveMapToolStripMenuItem1, this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			this->fileToolStripMenuItem->Visible = false;
			// 
			// newClearAllToolStripMenuItem
			// 
			this->newClearAllToolStripMenuItem->Name = L"newClearAllToolStripMenuItem";
			this->newClearAllToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->newClearAllToolStripMenuItem->Text = L"New (Clear All)";
			// 
			// openMapToolStripMenuItem
			// 
			this->openMapToolStripMenuItem->Name = L"openMapToolStripMenuItem";
			this->openMapToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->openMapToolStripMenuItem->Text = L"Open";
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->saveAsToolStripMenuItem->Text = L"Save As";
			// 
			// saveMapToolStripMenuItem1
			// 
			this->saveMapToolStripMenuItem1->Name = L"saveMapToolStripMenuItem1";
			this->saveMapToolStripMenuItem1->Size = System::Drawing::Size(153, 22);
			this->saveMapToolStripMenuItem1->Text = L"Save";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(153, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->showGridToolStripMenuItem,
					this->pixelSizeToolStripMenuItem, this->penColorToolStripMenuItem
			});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// showGridToolStripMenuItem
			// 
			this->showGridToolStripMenuItem->CheckOnClick = true;
			this->showGridToolStripMenuItem->Name = L"showGridToolStripMenuItem";
			this->showGridToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->showGridToolStripMenuItem->Text = L"Show Grid";
			this->showGridToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::showGridToolStripMenuItem_Click);
			// 
			// pixelSizeToolStripMenuItem
			// 
			this->pixelSizeToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->pixelSizeToolStripComboBox });
			this->pixelSizeToolStripMenuItem->Name = L"pixelSizeToolStripMenuItem";
			this->pixelSizeToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->pixelSizeToolStripMenuItem->Text = L"Pixel Size";
			// 
			// pixelSizeToolStripComboBox
			// 
			this->pixelSizeToolStripComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"20", L"30", L"40", L"50" });
			this->pixelSizeToolStripComboBox->Name = L"pixelSizeToolStripComboBox";
			this->pixelSizeToolStripComboBox->Size = System::Drawing::Size(121, 23);
			this->pixelSizeToolStripComboBox->Text = L"40";
			this->pixelSizeToolStripComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::pixelSizeToolStripComboBox_SelectedIndexChanged);
			// 
			// penColorToolStripMenuItem
			// 
			this->penColorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->penColortoolStripComboBox });
			this->penColorToolStripMenuItem->Name = L"penColorToolStripMenuItem";
			this->penColorToolStripMenuItem->Size = System::Drawing::Size(128, 22);
			this->penColorToolStripMenuItem->Text = L"Pen Color";
			// 
			// penColortoolStripComboBox
			// 
			this->penColortoolStripComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Black", L"Brown", L"Red", L"Green",
					L"Blue"
			});
			this->penColortoolStripComboBox->Name = L"penColortoolStripComboBox";
			this->penColortoolStripComboBox->Size = System::Drawing::Size(121, 23);
			this->penColortoolStripComboBox->Text = L"Black";
			this->penColortoolStripComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::penColortoolStripComboBox_SelectedIndexChanged);
			// 
			// actionsToolStripMenuItem
			// 
			this->actionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->enableDotToolStripMenuItem,
					this->enablePenToolStripMenuItem, this->setStartToolStripMenuItem, this->setEndToolStripMenuItem, this->clearAllToolStripMenuItem
			});
			this->actionsToolStripMenuItem->Name = L"actionsToolStripMenuItem";
			this->actionsToolStripMenuItem->Size = System::Drawing::Size(90, 20);
			this->actionsToolStripMenuItem->Text = L"Map Drawing";
			// 
			// enableDotToolStripMenuItem
			// 
			this->enableDotToolStripMenuItem->CheckOnClick = true;
			this->enableDotToolStripMenuItem->Name = L"enableDotToolStripMenuItem";
			this->enableDotToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->enableDotToolStripMenuItem->Text = L"Enable Dot";
			this->enableDotToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::enableDotToolStripMenuItem_Click);
			// 
			// enablePenToolStripMenuItem
			// 
			this->enablePenToolStripMenuItem->Checked = true;
			this->enablePenToolStripMenuItem->CheckOnClick = true;
			this->enablePenToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
			this->enablePenToolStripMenuItem->Name = L"enablePenToolStripMenuItem";
			this->enablePenToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->enablePenToolStripMenuItem->Text = L"Enable Pen";
			this->enablePenToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::enablePenToolStripMenuItem_Click);
			// 
			// setStartToolStripMenuItem
			// 
			this->setStartToolStripMenuItem->CheckOnClick = true;
			this->setStartToolStripMenuItem->Name = L"setStartToolStripMenuItem";
			this->setStartToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->setStartToolStripMenuItem->Text = L"Set Start";
			this->setStartToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::setStartToolStripMenuItem_Click);
			// 
			// setEndToolStripMenuItem
			// 
			this->setEndToolStripMenuItem->CheckOnClick = true;
			this->setEndToolStripMenuItem->Name = L"setEndToolStripMenuItem";
			this->setEndToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->setEndToolStripMenuItem->Text = L"Set End";
			this->setEndToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::setEndToolStripMenuItem_Click);
			// 
			// clearAllToolStripMenuItem
			// 
			this->clearAllToolStripMenuItem->Name = L"clearAllToolStripMenuItem";
			this->clearAllToolStripMenuItem->Size = System::Drawing::Size(132, 22);
			this->clearAllToolStripMenuItem->Text = L"Clear All";
			this->clearAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::clearAllToolStripMenuItem_Click);
			// 
			// findPathToolStripMenuItem
			// 
			this->findPathToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->firstFoundToolStripMenuItem,
					this->shortestOfAllToolStripMenuItem
			});
			this->findPathToolStripMenuItem->Name = L"findPathToolStripMenuItem";
			this->findPathToolStripMenuItem->Size = System::Drawing::Size(69, 20);
			this->findPathToolStripMenuItem->Text = L"Find Path";
			// 
			// firstFoundToolStripMenuItem
			// 
			this->firstFoundToolStripMenuItem->Name = L"firstFoundToolStripMenuItem";
			this->firstFoundToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->firstFoundToolStripMenuItem->Text = L"First Found";
			this->firstFoundToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::firstFoundToolStripMenuItem_Click);
			// 
			// shortestOfAllToolStripMenuItem
			// 
			this->shortestOfAllToolStripMenuItem->Name = L"shortestOfAllToolStripMenuItem";
			this->shortestOfAllToolStripMenuItem->Size = System::Drawing::Size(150, 22);
			this->shortestOfAllToolStripMenuItem->Text = L"Shortest Of All";
			this->shortestOfAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::shortestOfAllToolStripMenuItem_Click);
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->aboutToolStripMenuItem,
					this->userManualToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// userManualToolStripMenuItem
			// 
			this->userManualToolStripMenuItem->Name = L"userManualToolStripMenuItem";
			this->userManualToolStripMenuItem->Size = System::Drawing::Size(140, 22);
			this->userManualToolStripMenuItem->Text = L"User Manual";
			this->userManualToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::userManualToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(399, 400);
			this->Controls->Add(this->mapFindPathSystemMenuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->mapFindPathSystemMenuStrip;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Ebubekir Yapay Zeka - Robot Shortest Path";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->mapFindPathSystemMenuStrip->ResumeLayout(false);
			this->mapFindPathSystemMenuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {

		formGraphics = CreateGraphics();
		myPen = gcnew Pen(Color::Black);
		brush = gcnew SolidBrush(Color::Black);

		pixelSize = Convert::ToInt32(pixelSizeToolStripComboBox->Text);
		widthPixelNo = this->Width / pixelSize;
		heightPixelNo = this->Height / pixelSize;

		pixels = new int* [widthPixelNo];
		for (int i = 0; i < widthPixelNo; i++)
			pixels[i] = new int[heightPixelNo];

		for (int i = 0; i < widthPixelNo; i++)
			for (int j = 0; j < heightPixelNo; j++)
				pixels[i][j] = 0;


		tempPixels = new int* [widthPixelNo];
		for (int i = 0; i < widthPixelNo; i++)
			tempPixels[i] = new int[heightPixelNo];

		optPixels = new int* [widthPixelNo];
		for (int i = 0; i < widthPixelNo; i++)
			optPixels[i] = new int[heightPixelNo];



		a = new int[4]{ -1,0,1,0 };
		b = new int[4]{ 0,1,0,-1 };

	}

#pragma region MouseEvents
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		changesFound = true;
		if (enablePenToolStripMenuItem->Checked)
			this->drawStart = Point(e->X, e->Y);
	}

	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (enablePenToolStripMenuItem->Checked && e->Button == System::Windows::Forms::MouseButtons::Left) {
			track.Add(drawStart);
			DrawEnd.X = e->X;
			DrawEnd.Y = e->Y;
			track.Add(DrawEnd);
			//formGraphics->DrawLine(myPen, drawStart, DrawEnd);
			drawStart.X = e->X;
			drawStart.Y = e->Y;
		}
		showPixels();
	}

		   void showPixels() {

			   int i, j, k;
			   for (int i = 0; i < widthPixelNo; i++)
				   for (int j = 0; j < heightPixelNo; j++)
					   tempPixels[i][j] = 0;

			   for (k = 0; k < track.Count; k++)
			   {
				   i = track[k].X / pixelSize;
				   j = track[k].Y / pixelSize;

				   if (i < 0 || i >= widthPixelNo || j < 0 || j >= heightPixelNo)
					   continue;

				   if ((!mazeStart.IsEmpty && i == mazeStart.X && j == mazeStart.Y) ||
					   (!mazeEnd.IsEmpty && i == mazeEnd.X && j == mazeEnd.Y)) {
					   System::Windows::Forms::DialogResult DR;
					   DR = MessageBox::Show("You can not pick a seized point in the map. \n\n Click on it to free it again", "Invalid Point !!!",
						   System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
					   continue;
				   }

				   pixels[i][j] = 1;
				   tempPixels[i][j] = 1;
			   }
			   for (i = 0; i < widthPixelNo; i++)
				   for (j = 0; j < heightPixelNo; j++)
					   if (tempPixels[i][j] == 1)
						   formGraphics->FillRectangle(brush, i * pixelSize + 1, j * pixelSize + 1, pixelSize - 1, pixelSize - 1);
			   track.Clear();
		   }

	private: System::Void MyForm_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		if (enablePenToolStripMenuItem->Checked)
			return;
		int i = e->X / pixelSize, j = e->Y / pixelSize;
		//Start End Points
		if (setStartToolStripMenuItem->Checked || setEndToolStripMenuItem->Checked)
		{
			if (pixels[i][j] == 1) {
				System::Windows::Forms::DialogResult DR;
				DR = MessageBox::Show("You can not pick a seized point in the map. \n\n Click on it to free it again", "Invalid Point !!!",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
				return;
			}

			Point selectedPixel = Point(i, j);
			SolidBrush^ specialBrush = gcnew SolidBrush(Color::White);
			String^ pointNo = " ";

			//Clear old
			if (setStartToolStripMenuItem->Checked) {
				if (!mazeStart.IsEmpty) {
					formGraphics->FillRectangle(specialBrush, mazeStart.X * pixelSize + 1, mazeStart.Y * pixelSize + 1, pixelSize - 1, pixelSize - 1);
					pixels[mazeStart.X][mazeStart.Y] = 0;
				}

				mazeStart = selectedPixel;
				pixels[i][j] = 2;
				pointNo = "1";

			}
			else {//setEndToolStripMenuItem->Checked
				if (!mazeEnd.IsEmpty) {
					formGraphics->FillRectangle(specialBrush, mazeEnd.X * pixelSize + 1, mazeEnd.Y * pixelSize + 1, pixelSize - 1, pixelSize - 1);
					pixels[mazeEnd.X][mazeEnd.Y] = 0;
				}

				mazeEnd = selectedPixel;
				pixels[i][j] = 2;
				pointNo = "2";
			}
			//Draw new
			specialBrush->Color = Color::Gold;
			formGraphics->FillRectangle(specialBrush, selectedPixel.X * pixelSize + 1, selectedPixel.Y * pixelSize + 1, pixelSize - 1, pixelSize - 1);
			FontFamily^ fntFamily = gcnew FontFamily(L"Times New Roman");
			System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, pixelSize / 2, FontStyle::Regular);
			formGraphics->DrawString(pointNo, fntWrite, Brushes::Blue, selectedPixel.X * pixelSize + pixelSize / 4, selectedPixel.Y * pixelSize + pixelSize / 4);
		}
		else { //Normal
			if ((!mazeStart.IsEmpty && i == mazeStart.X && j == mazeStart.Y) ||
				(!mazeEnd.IsEmpty && i == mazeEnd.X && j == mazeEnd.Y)) {
				System::Windows::Forms::DialogResult DR;
				DR = MessageBox::Show("You can not pick a seized point in the map. \n\n Click on it to free it again", "Invalid Point !!!",
					System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
			}
			else if (pixels[i][j] == 1) {
				pixels[i][j] = 0;
				formGraphics->FillRectangle(gcnew SolidBrush(Color::White), i * pixelSize + 1, j * pixelSize + 1, pixelSize - 1, pixelSize - 1);
			}
			else {
				pixels[i][j] = 1;
				formGraphics->FillRectangle(brush, i * pixelSize + 1, j * pixelSize + 1, pixelSize - 1, pixelSize - 1);
			}

		}
	}

#pragma endregion

#pragma region MapOptions

	private: System::Void showGridToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		Pen^ pen = gcnew Pen(Color::Black);

		if (showGridToolStripMenuItem->Checked)
			pen->Color = Color::Black;
		else
			pen->Color = Color::White;

		for (int i = 0; i <= widthPixelNo; i++)
			formGraphics->DrawLine(pen, i * pixelSize, 0, i * pixelSize, this->Height);
		for (int j = 0; j <= heightPixelNo; j++)
			formGraphics->DrawLine(pen, 0, j * pixelSize, this->Width, j * pixelSize);
	}

	private: System::Void pixelSizeToolStripComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult DR;
		DR = MessageBox::Show("Changing the pixel size will clear all drawings. \n Do You want to continue? ", "Reseting Drawing !!!",
			System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Warning);
		if (DR == System::Windows::Forms::DialogResult::Yes) {

			pixelSize = (pixelSizeToolStripComboBox->SelectedIndex + 2) * 10;
			widthPixelNo = this->Width / pixelSize;
			heightPixelNo = this->Height / pixelSize;

			clearMap();

		}
	}

	private: System::Void penColortoolStripComboBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		switch (penColortoolStripComboBox->SelectedIndex)
		{
		case 1:
			myPen->Color = Color::Brown;
			brush->Color = Color::Brown;
			break;
		case 2:
			myPen->Color = Color::Red;
			brush->Color = Color::Red;
			break;
		case 3:
			myPen->Color = Color::Green;
			brush->Color = Color::Green;
			break;
		case 4:
			myPen->Color = Color::Blue;
			brush->Color = Color::Blue;
			break;
		default:
			myPen->Color = Color::Black;
			brush->Color = Color::Black;
			break;
		}
	}

#pragma endregion

#pragma region MapDrawing

	private: System::Void enableDotToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		enablePenToolStripMenuItem->Checked = false;
		setStartToolStripMenuItem->Checked = false;
		setEndToolStripMenuItem->Checked = false;
	}
	private: System::Void enablePenToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		enableDotToolStripMenuItem->Checked = false;
		setStartToolStripMenuItem->Checked = false;
		setEndToolStripMenuItem->Checked = false;
	}
	private: System::Void setStartToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		enableDotToolStripMenuItem->Checked = false;
		enablePenToolStripMenuItem->Checked = false;
		setEndToolStripMenuItem->Checked = false;
	}

	private: System::Void setEndToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		enableDotToolStripMenuItem->Checked = false;
		enablePenToolStripMenuItem->Checked = false;
		setStartToolStripMenuItem->Checked = false;
	}

	private: System::Void clearAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		clearMap();
	}

		   void clearMap()
		   {
			   track.Clear();
			   formGraphics->Clear(Color::White);

			   delete[] pixels;
			   delete[] tempPixels;

			   pixels = new int* [widthPixelNo];
			   for (int i = 0; i < widthPixelNo; i++)
				   pixels[i] = new int[heightPixelNo];

			   tempPixels = new int* [widthPixelNo];
			   for (int i = 0; i < widthPixelNo; i++)
				   tempPixels[i] = new int[heightPixelNo];

			   for (int i = 0; i < widthPixelNo; i++)
				   for (int j = 0; j < heightPixelNo; j++)
					   pixels[i][j] = 0;

			   showGridToolStripMenuItem->Checked = false;
			   mazeStart = Point();
			   mazeEnd = Point();
			   firstSolFound = false;
			   optSolFound = false;
		   }

#pragma endregion

#pragma region MapFindPath


		   void clearPrevSolution()
		   {
			   for (int i = 0; i < widthPixelNo; i++)
				   for (int j = 0; j < heightPixelNo; j++)
					   if (pixels[i][j] > 2 || (optPixels[i][j] > 2 && pixels[i][j] != 1)) {
						   formGraphics->FillRectangle(gcnew SolidBrush(Color::White), i * pixelSize + 1, j * pixelSize + 1, pixelSize - 1, pixelSize - 1);
						   pixels[i][j] = 0;
					   }
		   }

		   void drawSolution(int** solPixels, Color brushColor)
		   {
			   SolidBrush^ resultBrush = gcnew SolidBrush(brushColor);
			   FontFamily^ fntFamily = gcnew FontFamily(L"Times New Roman");
			   System::Drawing::Font^ fntWrite = gcnew System::Drawing::Font(fntFamily, pixelSize / 2, FontStyle::Regular);

			   for (int i = 0; i < widthPixelNo; i++)
				   for (int j = 0; j < heightPixelNo; j++)
					   if (solPixels[i][j] > 1) {
						   formGraphics->FillRectangle(resultBrush, i * pixelSize + 1, j * pixelSize + 1, pixelSize - 1, pixelSize - 1);
						   formGraphics->DrawString((solPixels[i][j] - 1).ToString(), fntWrite, Brushes::White, i * pixelSize, j * pixelSize + pixelSize / 4);
					   }
		   }


	private: System::Void firstFoundToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		if (mazeStart.IsEmpty || mazeEnd.IsEmpty)
		{
			System::Windows::Forms::DialogResult DR;
			DR = MessageBox::Show("You did not yet set the start and end points. \n\n You can find that in the Map Drawing menu", "Start / End Points !!!",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
			return;
		}
		
		clearPrevSolution();
	
		pixels[mazeEnd.X][mazeEnd.Y] = 0;
		tryFirstFound(3, mazeStart.X, mazeStart.Y);
		if (pixels[mazeEnd.X][mazeEnd.Y] != 0) {
			firstSolFound = true;
			drawSolution(pixels, Color::Gray);
		}
		else {
			System::Windows::Forms::DialogResult DR;
			DR = MessageBox::Show("No solution hass been found please update the map.", "Blocked Path !!!",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		}
	}

		   void tryFirstFound(int i, int x, int y)
		   {
			   int u, v, k = -1;
			   do {
				   ++k;
				   u = x + a[k]; v = y + b[k];
				   if ((u >= 0) && (u < widthPixelNo) && (v >= 0) && (v < heightPixelNo) && (pixels[u][v] == 0))
				   {
					   pixels[u][v] = i;
					   if ((u == mazeEnd.X) && (v == mazeEnd.Y)) // yes , the solution is complete
						   return;
					   else
					   {
						   tryFirstFound(i + 1, u, v);
						   if (pixels[mazeEnd.X][mazeEnd.Y] == 0)
							   pixels[u][v] = 0;
						   else return; // a solution has been found
					   }
				   }
			   } while (k < 3);
		   }

	private: System::Void shortestOfAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		if (mazeStart.IsEmpty || mazeEnd.IsEmpty)
		{
			System::Windows::Forms::DialogResult DR;
			DR = MessageBox::Show("You did not yet set the start and end points. \n\n You can find that in the Map Drawing menu", "Start / End Points !!!",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Warning);
			return;
		}

		if (firstSolFound)
			clearPrevSolution();

		if (optSolFound && !changesFound) {
			drawSolution(optPixels, Color::Gold);
			return;
		}
			   
		minLenght = widthPixelNo * heightPixelNo;

		pixels[mazeEnd.X][mazeEnd.Y] = 0;

		tryOptimized(3, mazeStart.X, mazeStart.Y);
		if (optPixels[mazeEnd.X][mazeEnd.Y] != 0) {
			optSolFound = true;
			drawSolution(optPixels, Color::Gold);
		}
		else {
			System::Windows::Forms::DialogResult DR;
			DR = MessageBox::Show("No solution hass been found please update the map.", "Blocked Path !!!",
				System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Information);
		}
		changesFound = false;
	}
		   
		   void tryOptimized(int i, int x, int y)
		   {
			   int u, v, k = -1;
			   do {
				   ++k;
				   u = x + a[k]; v = y + b[k];
				   if ((u >= 0) && (u < widthPixelNo) && (v >= 0) && (v < heightPixelNo) && (pixels[u][v] == 0))
				   {
					   pixels[u][v] = i;
					   if ((u == mazeEnd.X) && (v == mazeEnd.Y))
					   {
						   if (i < minLenght)
						   {
							   minLenght = i;
							   for (int w = 0; w < widthPixelNo; w++)
								   for (int t = 0; t < heightPixelNo; t++)
									   optPixels[w][t] = pixels[w][t];
						   }
					   }
					   else if (i + 1 < minLenght)
						   tryOptimized(i + 1, u, v);

					   pixels[u][v] = 0;
				   }
			   } while (k < 3);
		   }

#pragma endregion

#pragma region MapHelp

	private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult DR;
		DR = MessageBox::Show("This application is programmed by \n\n Eng. ABO BAKR ALMOSTAFA", "All rights are reserved for the author !!!",
			System::Windows::Forms::MessageBoxButtons::OK, System::Windows::Forms::MessageBoxIcon::Asterisk);
	}

	private: System::Void userManualToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		System::Windows::Forms::DialogResult DR;
		DR = MessageBox::Show(
			"1)  \n\n " +
			"2)  \n\n " +
			"3)  \n\n " +
			"4)  \n\n " +
			"5)  \n\n " +
			"6)  \n\n " +
			"7)  \n\n " +
			"8)  \n\n ",
			"Quich Instructions:",
			System::Windows::Forms::MessageBoxButtons::OK);
	}

#pragma endregion

	};
}
