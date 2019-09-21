#include "Item.h"
#include "Category.h"
#include "ToDoList.h"

int main() {
    ToDoList list;

    list.addItem("Storia: Studiare da pag. 120 a pag. 145", "Compiti");
    list.addItem("Matematica: es. 1,2,3,4 pag. 56", "Compiti");
    list.addItem("Scienze: studiare pag. 112-113", "Compiti");

    list.viewList();
    std::cout<< "_________________________________________" << std::endl;

    list.updateItem("Matematica: es. 1,2,3,4 pag. 56", "Matematica: es. 5,6,7,8 pag. 56");
    list.updateItem("Storia: Studiare da pag. 120 a pag. 145", "Storia: Studiare da pag. 120 a pag. 148");

    list.viewList();
    std::cout<< "_________________________________________" << std::endl;

    list.addItem("17/07/2020 - Partenza per vacanze","Escursioni");
    list.addItem("20/07/2020 - Gita in barca","Escursioni");
    list.setDone("Matematica: es. 5,6,7,8 pag. 56", "Compiti");

    list.viewList();
    std::cout<< "_________________________________________" << std::endl;

    list.removeItem("Storia: Studiare da pag. 120 a pag. 148", "Compiti");

    list.viewList();
    std::cout<< "_________________________________________" << std::endl;

    list.addItem("Prova inserimento multiplo", "Compiti", "Escursioni");

    list.viewList();


}
