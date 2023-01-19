
#define ame_Windows

#include "aMonkeyEngine/System.hpp"
#include "aMonkeyEngine/WindowsFile.hpp"
#include "aMonkeyEngine/Lexer.hpp"
#include "aMonkeyEngine/Parser.hpp"
#include "aMonkeyEngine/ParserHelper.hpp"
#include "aMonkeyEngine/PrintableList.hpp"
#include "aMonkeyEngine/PrintableFullTree.hpp"

using namespace ame;

int main(){
    /*
    WindowsFile file;
    file.setRootPathFile("pocoyo");
    file.createRootFile("lolcito.txt");
    file.writeRootText("extra test", "lolcito.txt");
    Note note = file.readRootText("lolcito.txt");
    System::console.println(note);
    */


    Note script = "int x = 12;";

    Lexer lexer;

    Token intType("IntergerType","int");
    Token varToken = lexer.getToken("variable");
    Token equal("equal","=");
    Token intToken = lexer.getToken("0");
    Token endCode("endCode",";");

    lexer.addBreakPoint(' ');
    lexer.addTypeToken(intType);
    lexer.addDelimiterToken(equal);
    lexer.addDelimiterToken(endCode);

    PrimitiveList<Token>& token_list = lexer.capture(script);

    System::console.println(script);
    System::console.println(PrintableList<PrimitiveList<Token>,Token>(token_list));


    Token intAssigning("intAssing");

    Parser parser;
    parser.addTokenStructure(intAssigning, intType, varToken, equal, intToken, endCode);

    FullTree<Token>& tree = parser.generateTree(token_list);

    System::console.println(PrintableFullTree<Token>(tree));
    
    return 0;
}