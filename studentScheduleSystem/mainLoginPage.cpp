#include <cppconn/driver.h> 
#include <cppconn/exception.h> 
#include <cppconn/statement.h> 
#include <iostream> 
#include <mysql_connection.h> 
#include <mysql_driver.h> 
#include "mainLoginPage.h"

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main() {
    try {
        sql::mysql::MySQL_Driver* driver;
        sql::Connection* con;

        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://localhost:3306", "root", "jhan_M04!");

        con->setSchema("studentdatabase"); // your database name 

        sql::Statement* stmt;
        stmt = con->createStatement();

        // SQL query to retrieve data from the table 
        string selectDataSQL = "SELECT * FROM students";

        sql::ResultSet* res = stmt->executeQuery(selectDataSQL);

        // Loop through the result set and display data 
        int count = 0;
        while (res->next()) {
            cout << res->getString("first_name") << " " << res->getString("last_name") << " | " << res->getString("class_rank") << endl;
        }

        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "SQL Error: " << e.what() << std::endl;
    }

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	studentScheduleSystem::mainLoginPage form;
	Application::Run(% form);
}