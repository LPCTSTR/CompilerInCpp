#pragma once
#include "../GUI.h"
namespace Kashiko {
	class TextEditor {

		char* _text;
		unsigned int size;
		const static unsigned int def_size = 1024 * 16;
		
		TextEditor() {
			size = def_size;
			_text = new char[def_size] {


				"func mian(arc int, arg string) :\n"
				"	print(\"Hello World!!\")\n"
				"	end\n"
				"/*\n"
					" \tChinese Compiler\t \n"
					"By:\n"
					"\tLPCTSTR_MSR\n"
					"*/\n\n"
			};

		}

		/*
		increase the buffer of the data
		*/
		void grow(int cif);

		
	public:
		char* getText();

		void show();
		
		static TextEditor* GetInst() {
			static TextEditor* inst = nullptr;
			if (inst == nullptr)
				inst = new TextEditor;
			return inst;
		}


	};

}
