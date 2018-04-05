#include "grman/grman.h"
#include <iostream>
#include <map>
#include <allegro.h>
#include "graph.h"
using namespace std;
int main()
{
    /// A appeler en 1er avant d'instancier des objets graphiques etc...
    grman::init();


    BITMAP* page;
    BITMAP* fond;
    page=create_bitmap(SCREEN_W,SCREEN_H);

    fond = load_bitmap("aigle1.bmp", NULL);

    /// Le nom du répertoire où se trouvent les images à charger
    grman::set_pictures_path("pics");

    /// Un exemple de graphe
    Graph g;
    grman::menu_afficher(page,fond);




    while ( !key[KEY_ESC] )
    {


        while(mouse_b&1)
        {

            if (getpixel(screen,mouse_x,mouse_y)==makecol(225,206,154))

            {

                g.construct_food_chain();

                /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                g.update();

                /// Mise à jour générale (clavier/souris/buffer etc...)


            }

             if (getpixel(screen,mouse_x,mouse_y)==makecol(121,121,248))

            {

                g.construct_food_chain();

                /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                g.update();

                /// Mise à jour générale (clavier/souris/buffer etc...)


            }
            if (getpixel(screen,mouse_x,mouse_y)==makecol(127,206,114))

            {
                    exit(1);

            }

            if (getpixel(screen,mouse_x,mouse_y)==makecol(150,225,174))

            {

                g.construct_food_chain();

                /// Il faut appeler les méthodes d'update des objets qui comportent des widgets
                g.update();

                /// Mise à jour générale (clavier/souris/buffer etc...)


            }

                g.update();

                /// Mise à jour générale (clavier/souris/buffer etc...)
                grman::mettre_a_jour();


        }

    }



    grman::fermer_allegro();

    return 0;
}
END_OF_MAIN();

