#include "TextEditor.h"
namespace Kashiko {
    void TextEditor::grow(int cif) {
        unsigned int n_size = size << cif;
        char* n_p = new char[n_size];
        memcpy(n_p, _text, size);
        delete[] _text;
        _text = n_p;
        size = n_size;

    }

    char* TextEditor::getText()
    {
        return _text;
    }

    void TextEditor::show() {
        ImGui::Begin("TextEditor");
        static ImGuiInputTextFlags flags = ImGuiInputTextFlags_AllowTabInput;
        ImGui::InputTextMultiline("##source", _text, size, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 16), flags);
        ImGui::End();
    }

    
 

}
