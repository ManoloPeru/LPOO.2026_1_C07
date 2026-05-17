#pragma once
#include "frmNuevoUnidadRobotica.h"
#include "frmEditarUnidadRobotica.h"

namespace SGELProdAutomView {

	using namespace System;
	using namespace System::IO; // Se agrega esta directiva para poder usar la clase Path y Directory para manejar las rutas de los archivos de datos de tipos de robots, esto se puede modificar según sea necesario
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace SGELProdAutomModel;
	using namespace SGELProdAutomController;

	/// <summary>
	/// Resumen de frmMantUnidadRobotica
	/// </summary>
	public ref class frmMantUnidadRobotica : public System::Windows::Forms::Form
	{
	public:
		frmMantUnidadRobotica(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// Construye la ruta completa del directorio donde se almacenarán los archivos de datos, esto se puede modificar según sea necesario
			String^ pathArchivo = Path::Combine(Directory::GetParent(Directory::GetParent(Application::StartupPath)->FullName)->FullName, "BD\\TXT\\");
			this->tipoRobotController = gcnew TipoRobotController(pathArchivo);
			this->robotController = gcnew RobotController(pathArchivo);
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantUnidadRobotica()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnEliminar;
	protected:
	private: System::Windows::Forms::Button^ btnEditar;
	private: System::Windows::Forms::Button^ btnNuevo;
	private: System::Windows::Forms::DataGridView^ dgvLista;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnLimpiar;
	private: System::Windows::Forms::Button^ btnBuscar;
	private: System::Windows::Forms::TextBox^ txtSerialId;
	private: System::Windows::Forms::Label^ label1;

	private: RobotController^ robotController; // Variable para almacenar la instancia del controlador y poder realizar las operaciones de consulta, edición y eliminación de unidades robóticas
	private: TipoRobotController^ tipoRobotController;	// Variable para almacenar la instancia del controlador de tipos de robots y poder cargar los tipos disponibles en el ComboBox cmbTipoRobot

	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colSerialId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colAlias;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colUbicacion;
	private: System::Windows::Forms::ComboBox^ cmbTipoRobot;

	private: System::Windows::Forms::Label^ label2;






	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnEliminar = (gcnew System::Windows::Forms::Button());
			this->btnEditar = (gcnew System::Windows::Forms::Button());
			this->btnNuevo = (gcnew System::Windows::Forms::Button());
			this->dgvLista = (gcnew System::Windows::Forms::DataGridView());
			this->colSerialId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colAlias = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colUbicacion = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->cmbTipoRobot = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnLimpiar = (gcnew System::Windows::Forms::Button());
			this->btnBuscar = (gcnew System::Windows::Forms::Button());
			this->txtSerialId = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnEliminar
			// 
			this->btnEliminar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEliminar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEliminar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEliminar->Location = System::Drawing::Point(619, 475);
			this->btnEliminar->Margin = System::Windows::Forms::Padding(4);
			this->btnEliminar->Name = L"btnEliminar";
			this->btnEliminar->Size = System::Drawing::Size(98, 34);
			this->btnEliminar->TabIndex = 9;
			this->btnEliminar->Text = L"Eliminar";
			this->btnEliminar->UseVisualStyleBackColor = false;
			this->btnEliminar->Click += gcnew System::EventHandler(this, &frmMantUnidadRobotica::btnEliminar_Click);
			// 
			// btnEditar
			// 
			this->btnEditar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnEditar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnEditar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnEditar->Location = System::Drawing::Point(424, 475);
			this->btnEditar->Margin = System::Windows::Forms::Padding(4);
			this->btnEditar->Name = L"btnEditar";
			this->btnEditar->Size = System::Drawing::Size(98, 34);
			this->btnEditar->TabIndex = 8;
			this->btnEditar->Text = L"Editar";
			this->btnEditar->UseVisualStyleBackColor = false;
			this->btnEditar->Click += gcnew System::EventHandler(this, &frmMantUnidadRobotica::btnEditar_Click);
			// 
			// btnNuevo
			// 
			this->btnNuevo->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnNuevo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnNuevo->ForeColor = System::Drawing::SystemColors::Control;
			this->btnNuevo->Location = System::Drawing::Point(212, 475);
			this->btnNuevo->Margin = System::Windows::Forms::Padding(4);
			this->btnNuevo->Name = L"btnNuevo";
			this->btnNuevo->Size = System::Drawing::Size(98, 34);
			this->btnNuevo->TabIndex = 7;
			this->btnNuevo->Text = L"Nuevo";
			this->btnNuevo->UseVisualStyleBackColor = false;
			this->btnNuevo->Click += gcnew System::EventHandler(this, &frmMantUnidadRobotica::btnNuevo_Click);
			// 
			// dgvLista
			// 
			this->dgvLista->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgvLista->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvLista->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLista->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->colSerialId,
					this->colAlias, this->colTipo, this->colEstado, this->colUbicacion
			});
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLista->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLista->Location = System::Drawing::Point(13, 127);
			this->dgvLista->Margin = System::Windows::Forms::Padding(4);
			this->dgvLista->Name = L"dgvLista";
			this->dgvLista->RowHeadersWidth = 51;
			this->dgvLista->RowTemplate->Height = 24;
			this->dgvLista->Size = System::Drawing::Size(1041, 327);
			this->dgvLista->TabIndex = 11;
			// 
			// colSerialId
			// 
			this->colSerialId->HeaderText = L"SerialId";
			this->colSerialId->MinimumWidth = 6;
			this->colSerialId->Name = L"colSerialId";
			// 
			// colAlias
			// 
			this->colAlias->HeaderText = L"Nombre de Unidad Robótica";
			this->colAlias->MinimumWidth = 6;
			this->colAlias->Name = L"colAlias";
			this->colAlias->Width = 280;
			// 
			// colTipo
			// 
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->MinimumWidth = 6;
			this->colTipo->Name = L"colTipo";
			this->colTipo->Width = 120;
			// 
			// colEstado
			// 
			this->colEstado->HeaderText = L"Estado operativo";
			this->colEstado->MinimumWidth = 6;
			this->colEstado->Name = L"colEstado";
			this->colEstado->Width = 180;
			// 
			// colUbicacion
			// 
			this->colUbicacion->HeaderText = L"Ubicación";
			this->colUbicacion->Name = L"colUbicacion";
			this->colUbicacion->Width = 300;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->cmbTipoRobot);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->btnLimpiar);
			this->groupBox1->Controls->Add(this->btnBuscar);
			this->groupBox1->Controls->Add(this->txtSerialId);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(1041, 94);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// cmbTipoRobot
			// 
			this->cmbTipoRobot->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->cmbTipoRobot->FormattingEnabled = true;
			this->cmbTipoRobot->Location = System::Drawing::Point(517, 43);
			this->cmbTipoRobot->Name = L"cmbTipoRobot";
			this->cmbTipoRobot->Size = System::Drawing::Size(201, 30);
			this->cmbTipoRobot->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(377, 49);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(133, 24);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Tipo de robot :";
			// 
			// btnLimpiar
			// 
			this->btnLimpiar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnLimpiar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLimpiar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnLimpiar->Location = System::Drawing::Point(911, 43);
			this->btnLimpiar->Margin = System::Windows::Forms::Padding(4);
			this->btnLimpiar->Name = L"btnLimpiar";
			this->btnLimpiar->Size = System::Drawing::Size(98, 34);
			this->btnLimpiar->TabIndex = 3;
			this->btnLimpiar->Text = L"Limpiar";
			this->btnLimpiar->UseVisualStyleBackColor = false;
			this->btnLimpiar->Click += gcnew System::EventHandler(this, &frmMantUnidadRobotica::btnLimpiar_Click);
			// 
			// btnBuscar
			// 
			this->btnBuscar->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnBuscar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBuscar->ForeColor = System::Drawing::SystemColors::Control;
			this->btnBuscar->Location = System::Drawing::Point(792, 43);
			this->btnBuscar->Margin = System::Windows::Forms::Padding(4);
			this->btnBuscar->Name = L"btnBuscar";
			this->btnBuscar->Size = System::Drawing::Size(98, 34);
			this->btnBuscar->TabIndex = 2;
			this->btnBuscar->Text = L"Buscar";
			this->btnBuscar->UseVisualStyleBackColor = false;
			this->btnBuscar->Click += gcnew System::EventHandler(this, &frmMantUnidadRobotica::btnBuscar_Click);
			// 
			// txtSerialId
			// 
			this->txtSerialId->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->txtSerialId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtSerialId->Location = System::Drawing::Point(98, 46);
			this->txtSerialId->Margin = System::Windows::Forms::Padding(4);
			this->txtSerialId->Name = L"txtSerialId";
			this->txtSerialId->Size = System::Drawing::Size(220, 28);
			this->txtSerialId->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 49);
			this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(82, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"SerialId :";
			// 
			// frmMantUnidadRobotica
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1067, 539);
			this->Controls->Add(this->btnEliminar);
			this->Controls->Add(this->btnEditar);
			this->Controls->Add(this->btnNuevo);
			this->Controls->Add(this->dgvLista);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmMantUnidadRobotica";
			this->Text = L"Mantenimiento de Unidades Robóticas";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &frmMantUnidadRobotica::frmMantUnidadRobotica_FormClosing);
			this->Load += gcnew System::EventHandler(this, &frmMantUnidadRobotica::frmMantUnidadRobotica_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLista))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		// Método para mostrar la lista de unidadRoboticaes en el DataGridView
	private: System::Void frmMantUnidadRobotica_Load(System::Object^ sender, System::EventArgs^ e) {
		//Paso 1: Listamos los Tipos de Robot desde el archivo tipoRobot.txt
		List<TipoRobot^>^ listaTiposRobot = this->tipoRobotController->ListarTiposRobot();
		//Paso 2: Cargamos los tipos de robot en el ComboBox cmbTipoRobot, mostrando el nombre pero manteniendo el ID como valor
		List<KeyValuePair<String^, String^>>^ items = gcnew List<KeyValuePair<String^, String^>>();
		for each (TipoRobot ^ obj in listaTiposRobot) {
			//Paso 3: Agregamos cada tipo de robot a la lista de items para el ComboBox, utilizando el ID como clave y el nombre como valor
			int id = obj->getIdTipoRobot();
			String^ nombre = obj->getTipoRobot();
			// Agregar el tipo de robot a la lista de items para el ComboBox
			items->Add(KeyValuePair<String^, String^>(id.ToString(), nombre));
		}
		// Configurar el ComboBox para mostrar el nombre pero mantener el ID como valor
		cmbTipoRobot->DataSource = items;
		cmbTipoRobot->DisplayMember = "Value"; // muestra el nombre
		cmbTipoRobot->ValueMember = "Key";     // mantiene el ID como valor
		cmbTipoRobot->SelectedIndex = -1;      // opcional: sin selección inicial

		// Cargar los unidadRoboticaes en el DataGridView al iniciar el formulario
		// Aquí deberías llamar a tu controlador para obtener la lista de unidadRoboticaes y llenarla en el DataGridView
		List<UnidadRobotica^>^ listaUnidadRoboticas = this->robotController->ListarUnidades();
		mostrarGrilla(listaUnidadRoboticas);
	}

		   // Método para mostrar la lista de unidadRoboticaes en el DataGridView
	private: System::Void btnBuscar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Obtener el idStatus del operador a buscar
		String^ serialId = txtSerialId->Text;
		String^ selectedId = "";
		String^ selectedName = "";
		// Obtener el id del tipo de robot seleccionado en el ComboBox cmbTipoRobot, si se ha seleccionado alguno
		if (cmbTipoRobot->SelectedIndex >= 0) {
			// Obtener el ID del tipo de robot seleccionado en el ComboBox
			selectedId = cmbTipoRobot->SelectedValue->ToString();
			selectedName = cmbTipoRobot->Text; // Obtener el nombre del tipo de robot seleccionado
		}

		List<UnidadRobotica^>^ listaFiltrada = this->robotController->ConsultarIdTipo(serialId, selectedName);
		// Crear una lista para mostrar el resultado en el DataGridView
		List<UnidadRobotica^>^ listaUnidadRobaticas = gcnew List<UnidadRobotica^>();
		if (listaFiltrada != nullptr) {
			// Mostrar los resultados en el DataGridView
			mostrarGrilla(listaFiltrada);
		}
		else
		{	// Si no se encuentra unidad robótica, mostrar un mensaje de error
			MessageBox::Show("Por favor, ingrese un serialId.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   // Evento del botón Limpiar para limpiar el campo de búsqueda y mostrar todos los operadores
	private: System::Void btnLimpiar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Limpiar el campo de búsqueda
		List<UnidadRobotica^>^ listaUnidadRoboticas = this->robotController->ListarUnidades();
		// Mostrar todos los operadores en el DataGridView
		mostrarGrilla(listaUnidadRoboticas);
	}
	   
		   // Evento del botón Nuevo para abrir el formulario de nuevo operador
	private: System::Void btnNuevo_Click(System::Object^ sender, System::EventArgs^ e) {
		// Crear una nueva instancia del formulario de nuevo operador
		// y mostrarlo como un formulario hijo dentro del contenedor MDI
		frmNuevoUnidadRobotica^ nuevoUnidadRoboticaForm = gcnew frmNuevoUnidadRobotica(this->robotController, this->tipoRobotController);
		nuevoUnidadRoboticaForm->ShowDialog(this);
		// Llamar al método para cargar la lista de operadores nuevamente
		List<UnidadRobotica^>^ listaUnidadRoboticas = this->robotController->ListarUnidades();
		mostrarGrilla(listaUnidadRoboticas);
	}
		   // Evento del botón Editar para abrir el formulario de edición del operador seleccionado
	private: System::Void btnEditar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{
			int filaSeleccionada = this->dgvLista->SelectedRows[0]->Index;
			String^ serialId = this->dgvLista->Rows[filaSeleccionada]->Cells[0]->Value->ToString();

			UnidadRobotica^ unidadSeleccionado = this->robotController->ConsultarUnidad(serialId);
			if (unidadSeleccionado == nullptr)
			{
				MessageBox::Show("No se encontró la unidad robótica seleccionada.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			// Crear una nueva instancia del formulario de nuevo operador
			// y mostrarlo como un formulario hijo dentro del contenedor MDI
			frmEditarUnidadRobotica^ editarUnidadRoboticaForm = gcnew frmEditarUnidadRobotica(this->robotController, this->tipoRobotController, unidadSeleccionado);
			editarUnidadRoboticaForm->ShowDialog();
			// Llamar al m�todo para cargar la lista de operadores nuevamente
			List<UnidadRobotica^>^ listaUnidadRoboticas = this->robotController->ListarUnidades();
			mostrarGrilla(listaUnidadRoboticas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para editar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}

		   // Evento del botón Eliminar para eliminar el operador seleccionado
	private: System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e) {
		// Verificar si se ha seleccionado una fila en el DataGridView
		if (this->dgvLista->SelectedRows->Count > 0)
		{

			// Preguntar al usuario si est� seguro de eliminar el registro
			System::Windows::Forms::DialogResult respuesta = MessageBox::Show("¿Está seguro de que desea eliminar el registro seleccionado?",
				"Confirmación de eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			// Si el usuario selecciona "No", cancelar la operaci�n
			if (respuesta == System::Windows::Forms::DialogResult::No)
			{
				return; // Salir del evento si el usuario cancela
			}

			int selectedRowIndex = this->dgvLista->SelectedRows[0]->Index;
			String^ serialId = this->dgvLista->Rows[selectedRowIndex]->Cells[0]->Value->ToString();
			// Crear una instancia del controlador y eliminar el operador
			String^ resultado = this->robotController->EliminarUnidad(serialId);
			if (resultado->Equals("")) {
				MessageBox::Show("Unidad robótica eliminada exitosamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
			}
			else
			{
				MessageBox::Show("Error al eliminar la unidad robótica: " + resultado, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error); 
				return;
			}
			// Actualizar la lista de operadores en el DataGridView
			List<UnidadRobotica^>^ listaUnidadRoboticas = this->robotController->ListarUnidades();
			mostrarGrilla(listaUnidadRoboticas);
		}
		else
		{
			MessageBox::Show("Por favor, seleccione un operador para eliminar.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		}
	}
	
		   /*METODOSPERSONALES*/
		// Método para mostrar la lista de operadores en el DataGridView
	public:	void mostrarGrilla(List<UnidadRobotica^>^ listaUnidadRoboticas)
	{
		this->dgvLista->Rows->Clear();
		for (int i = 0; i < listaUnidadRoboticas->Count; i++)
		{
			// Obtener la unidad robótica actual de la lista
			UnidadRobotica^ unidadRobotica = listaUnidadRoboticas[i];
			// Crear un arreglo de strings para representar la fila del DataGridView
			array<String^>^ filaGrilla = gcnew array<String^>(7);
			// Asignar los valores de las propiedades de la unidad robótica a cada columna de la fila
			filaGrilla[0] = Convert::ToString(unidadRobotica->getSerialId());
			filaGrilla[1] = unidadRobotica->getAlias();
			filaGrilla[2] = unidadRobotica->getTipo();
			filaGrilla[3] = unidadRobotica->ObtenerEstadoString();
			filaGrilla[4] = unidadRobotica->getUbicacion();
			// Agregar la fila al DataGridView
			this->dgvLista->Rows->Add(filaGrilla);
		}
		this->dgvLista->AutoGenerateColumns = false; // Desactivar la generaci�n autom�tica de columnas
		this->dgvLista->AllowUserToAddRows = false;	 // Evitar que el usuario pueda agregar filas manualmente
		this->dgvLista->AutoResizeColumns(DataGridViewAutoSizeColumnsMode::AllCells); // Ajustar el ancho de las columnas al contenido
	}
	private: System::Void frmMantUnidadRobotica_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		// Este evento se dispara cuando el formulario se está cerrando
	// Puedes realizar acciones de limpieza aquí
	// Ejemplo: Guardar configuración, liberar recursos, etc.
	// MessageBox::Show("El formulario se está cerrando", "Cerrando");
		this->robotController->LibreraMemoria();
		// Opcional: Puedes cancelar el cierre si es necesario
		// if (condicion) {
		//     e->Cancel = true;
		//     MessageBox::Show("El cierre fue cancelado");
		//
	}
};
}
