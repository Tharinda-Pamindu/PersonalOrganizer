#pragma once
#include"LoginForm.h"
#include"RegisterForm.h"
#include"Main.h"
#include"StartUp.h"

using namespace System;
using namespace System::Windows::Forms;

public ref class ManageMe {
public: 
	ManageMe() { 
		Application::EnableVisualStyles();
		Application::SetCompatibleTextRenderingDefault(false);

		PersonalOrganizer::StartUp s;
		Application::Run(% s);
	}
public : void Start() {

		User^ user = nullptr;

		while (true) {

			PersonalOrganizer::LoginForm loginForm;
			loginForm.ShowDialog();

			if (loginForm.shiftToRegister) {

				PersonalOrganizer::RegisterForm registerForm;
				registerForm.ShowDialog();

				if (registerForm.shiftToLogin) {
					continue;
				}
				else {
					user = registerForm.user;
					break;
				}
			}
			else {
				user = loginForm.user;
				break;
			}
		}

		if (user != nullptr) {
			PersonalOrganizer::Main main(user);
			Application::Run(% main);

			if (main.logOut) {
				Start();
			}

		}

	}
};
