#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace System::IO;


public ref class DBConnection {
private:
	static DBConnection^ connection = nullptr;
	SqlConnection^ sqlConnection;
	DBConnection() {
			sqlConnection = gcnew SqlConnection("Data Source=THARINDA\\SQLEXPRESS;Initial Catalog=PersonalOrganiser;Integrated Security=True;Encrypt=False");
	}
public:
	static DBConnection^ GetInstance() {
		return connection = connection == nullptr ? gcnew DBConnection() : connection;
	}
	void OpenConnection() {
		if (sqlConnection->State != System::Data::ConnectionState::Open) {
			sqlConnection->Open();
		}
	}
	void CloseConnection() {
		if (sqlConnection->State == System::Data::ConnectionState::Open) {
			sqlConnection->Close();
		}
	}
	SqlConnection^ GetConnection() {
		return sqlConnection;
	}
};