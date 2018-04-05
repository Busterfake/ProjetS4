#include "graph.h"
#include <fstream>
#include <iostream>

/***************************************************
                    GRAPH
****************************************************/

using namespace std;

/// Ici le constructeur se contente de préparer un cadre d'accueil des
/// éléments qui seront ensuite ajoutés lors de la mise ne place du Graphe
GraphInterface::GraphInterface(int x, int y, int w, int h)
{



    m_top_box.set_dim(1000,740);
    m_top_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);

    m_top_box.add_child(m_main_box);
    m_main_box.set_dim(808,720);
    m_main_box.set_gravity_xy(grman::GravityX::Right, grman::GravityY::Up);
    m_main_box.set_bg_color(BLANCJAUNE);

    m_top_box.add_child(m_tool_box);
    m_tool_box.set_dim(180,720);
    m_tool_box.set_gravity_xy(grman::GravityX::Left, grman::GravityY::Up);
    m_tool_box.set_bg_color(BLANCBLEU);


    m_top_box.add_child(m_bouton_delete);
    m_bouton_delete.set_frame(15,250,160,50);
    m_bouton_delete.set_bg_color(BLANCROSE);
    m_bouton_delete.add_child(m_delete);
    m_delete.set_message("Supprimer sommet");
    m_delete.set_gravity_y(grman::GravityY::Center);


    m_top_box.add_child(m_bouton_add);
    m_bouton_add.set_frame(15,310,160,50);
    m_bouton_add.set_bg_color(BLEUCLAIR);
    m_bouton_add.add_child(m_add);
    m_add.set_message("Ajouter sommet");
    m_add.set_gravity_y(grman::GravityY::Center);

    m_top_box.add_child(m_bouton_save);
    m_bouton_save.set_frame(15,370,160,50);
    m_bouton_save.set_bg_color(BLANCJAUNE);
    m_bouton_save.add_child(m_save);
    m_save.set_message("Sauvegarder");
    m_save.set_gravity_y(grman::GravityY::Center);

    m_top_box.add_child(m_bouton_return);
    m_bouton_return.set_frame(15,430,160,50);
    m_bouton_return.set_bg_color(GRISCLAIR);
    m_bouton_return.add_child(m_return);
    m_return.set_message("Retour");
    m_return.set_gravity_y(grman::GravityY::Center);



}


void Graph::action_bouton()
{
     while(mouse_b&1)
        {

            if (getpixel(screen,mouse_x,mouse_y)==makecol(30,144,255))
            {
                    exit(1);
            }
}
}

void Graph::charger_matrice()
{
    ifstream fichier ("matrice_test.txt", ios::in);
    int temps=0;
    string insectes;

    if(fichier)
    {
        fichier>> m_ordre;
        for (int i=0; i<m_ordre; i++)
        {
            for (int j=0; j<m_ordre; j++)
            {
                fichier>>temps;
                m_collection_insectes[i][j]=temps;

            }
        }
//        for (int i=0; i<m_ordre; i++)
//        {
//            fichier>>insectes;
//            m_sommet.push_back(a);
//        }
//
//         for (int i=0; i<m_ordre; i++)
//        {
//            for (int j=0; j<m_ordre; j++)
//            {
//
//                std::cout<<m_collection_insectes[i][j]<<std::endl;
//
//            }
//        }
        fichier.close();
    }
     else cerr<<"Echec d'ouverture"<<endl;
}

void Graph::afficher_matrice()

{
    int m_ordre;

    for (int k=0;k<m_ordre; k++)
    {
        m_sommet[k].Afficher();
    }
    for (int i=0; i<m_ordre;i++)
    {
              for (int j=0; j<m_ordre;j++)
              {
                  std::cout<< m_collection_insectes[i][j]<<std::endl;
              }
    }
}
void Graph::allouer_mat (int ordre)
{
    m_matrice1=new int*[ordre];

    for(int i=0; i<ordre; i++)
    {
        m_matrice1[i]=new int[ordre];
    }
    for (int j=0; j<ordre; j++)
    {
        for(int k=0; k<ordre; k++)
        {
            m_matrice1[j][k]=0;
        }

    }
}

//
//void Graph::afficher()
//{
//    for (int i=0; i<m_ordre; i++)
//    {
//        for (int j=0; j<m_ordre; j++)
//        {
//            if(m_matrice1[i][j]==1)
//            {
//                std::cout<<m_matrice2[i].m_nom<<" influence "<<m_matrice2[j].m_nom<<std::endl;
//            }
//        }
//    }
//}



/// Méthode spéciale qui construit un graphe arbitraire (démo)
/// Cette méthode est à enlever et remplacer par un système
/// de chargement de fichiers par exemple.
/// Bien sûr on ne veut pas que vos graphes soient construits
/// "à la main" dans le code comme ça.
void Graph::make_example()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    // La ligne précédente est en gros équivalente à :
    // m_interface = new GraphInterface(50, 0, 750, 600);

    /// Les sommets doivent être définis avant les arcs
    // Ajouter le sommet d'indice 0 de valeur 30 en x=200 et y=100 avec l'image clown1.jpg etc...
    //add_interfaced_Sommet(0, 30.0, 200, 100, "jellyfish.jpg");
//    add_interfaced_Sommet(1, 60.0, 400, 100, "clown2.jpg");
//    add_interfaced_Sommet(2,  50.0, 200, 300, "clown3.jpg");
//    add_interfaced_Sommet(3,  0.0, 400, 300, "clown4.jpg");
//    add_interfaced_Sommet(4,  100.0, 600, 300, "clown5.jpg");
//    add_interfaced_Sommet(5,  0.0, 100, 500, "bad_clowns_xx3xx.jpg",0);
//    add_interfaced_Sommet(6,  0.0, 300, 500, "bad_clowns_xx3xx.jpg",1);
//    add_interfaced_Sommet(7,  0.0, 500, 500, "bad_clowns_xx3xx.jpg", 2);

    /// Les arcs doivent être définis entre des sommets qui existent !
//    // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
//    add_interfaced_Arete(0, 1, 2, 50.0);
//    add_interfaced_Arete(1, 0, 1, 50.0);
//    add_interfaced_Arete(2, 1, 3, 75.0);
//    add_interfaced_Arete(3, 4, 1, 25.0);
//    add_interfaced_Arete(4, 6, 3, 25.0);
//    add_interfaced_Arete(5, 7, 3, 25.0);
//    add_interfaced_Arete(6, 3, 4, 0.0);
//    add_interfaced_Arete(7, 2, 0, 100.0);
//    add_interfaced_Arete(8, 5, 2, 20.0);
//    add_interfaced_Arete(9, 3, 7, 80.0);
}

void Graph::construct_food_chain()
{
    m_interface = std::make_shared<GraphInterface>(50, 0, 750, 600);
    // La ligne précédente est en gros équivalente à :
    // m_interface = new GraphInterface(50, 0, 750, 600);

    chargerGraphe();

    std::map<int,Sommet> ::iterator it;

    for(it=m_vertices.begin(); it !=m_vertices.end(); it++)
    {
        cout<< "Indice du sommet : "<<it->first<< " | population : ";
        cout<<it->second.m_value<<std::endl;
    }

    auto it2 = m_vertices.find(2);

    if (it2!=m_vertices.end())
    {
        cout <<it2->second.m_value<<endl;

    }


    std::map<int,Arete> ::iterator it1;
    for(it1=m_Aretes.begin(); it1 !=m_Aretes.end(); it1++)
    {
        cout<< "Indice de l'arete : "<<it1->first<< " | poids arete : ";
        cout<<it1->second.m_weight<<std::endl;
    }


}

/// La méthode update à appeler dans la boucle de jeu pour les graphes avec interface
void Graph::update()
{
    if (!m_interface)
        return;

    for (auto &elt : m_vertices)
        elt.second.pre_update();

    for (auto &elt : m_Aretes)
        elt.second.pre_update();

    m_interface->m_top_box.update();

    for (auto &elt : m_vertices)
        elt.second.post_update();

    for (auto &elt : m_Aretes)
        elt.second.post_update();

}

/// Aide à l'ajout de sommets interfacés
void Graph::add_interfaced_Sommet(int idx, double value, int x, int y, std::string pic_name, int pic_idx )
{

    if ( m_vertices.find(idx)!=m_vertices.end() )
    {
        std::cerr << "Error adding Sommet at idx=" << idx << " already used..." << std::endl;
        throw "Error adding Sommet";
    }
    // Création d'une interface de sommet
    SommetInterface *vi = new SommetInterface(idx, x, y, pic_name, pic_idx);
    // Ajout de la top box de l'interface de sommet
    m_interface->m_main_box.add_child(vi->m_top_box);
    // On peut ajouter directement des vertices dans la map avec la notation crochet :
    m_vertices[idx] = Sommet(idx, value, vi);
}

/// Aide à l'ajout d'arcs interfacés
void Graph::add_interfaced_Arete(int idx, int id_vert1, int id_vert2, double weight)
{
    if ( m_Aretes.find(idx)!=m_Aretes.end() )
    {
        std::cerr << "Error adding Arete at idx=" << idx << " already used..." << std::endl;
        throw "Error adding Arete";
    }

    if ( m_vertices.find(id_vert1)==m_vertices.end() || m_vertices.find(id_vert2)==m_vertices.end() )
    {
        std::cerr << "Error adding Arete idx=" << idx << " between vertices " << id_vert1 << " and " << id_vert2 << " not in m_vertices" << std::endl;
        throw "Error adding Arete";
    }

    AreteInterface *ei = new AreteInterface(m_vertices[id_vert1], m_vertices[id_vert2]);
    m_interface->m_main_box.add_child(ei->m_top_Arete);
    m_Aretes[idx] = Arete(weight, ei);
    m_Aretes[idx].setIndice(idx);
}

void Graph::chargerGraphe()
{
    std::ifstream fichier("graphetest.txt", ios::in);

    if(fichier)
    {

        fichier >> m_ordre; //on récupère l'ordre de la matrice
        fichier >> m_nbArete; //on récupère le nombre d'arpete du graphe

        int indice_sommet;
        double jauge;
        //bool actif1;
        int x;
        int y;
        std::string image;
        // AJouter l'arc d'indice 0, allant du sommet 1 au sommet 2 de poids 50 etc...
        int indice_arc;
        int sommet_depart;
        int sommet_arrivee;
        double poids;

        cout<<"ordre : "<<m_ordre<<endl;
        cout<<"nb Aretes : "<<m_nbArete<<endl;

        for(int i=0; i<m_ordre; i++) //Pour remplir le tableau de Sommets (nom des individus) avec le fichier
        {
            fichier >> indice_sommet>>jauge>>x>>y>>image;


            cout<<"indice sommet : "<<indice_sommet<<endl;
            cout<<"jauge : "<<jauge<<endl;
            cout<<"x et y: "<<x<<" et "<<y<<endl;
            cout<<"nom image : "<<image<<endl;


            add_interfaced_Sommet(indice_sommet, jauge, x, y, image);
            cout<<"apres add interface sommet"<<endl;


        }

        for(int i=0; i<m_nbArete; i++)
        {
            fichier>>indice_arc>>sommet_depart>>sommet_arrivee>>poids;
            add_interfaced_Arete(indice_arc, sommet_depart, sommet_arrivee, poids);

        }


        cout<<endl;

        fichier.close();

    }
    else if(!fichier)
    {
        cout<<"PB D'OUVERTURE DU FICHIER"<<endl;
    }
}

void Graph::sauvegarderGraphe()
{

}

void Graph::ajouterSommet()
{

}

void Graph::supprimerSommet()
{

}


std::map<int,Sommet> Graph::getMapSommet()
{
    return m_vertices;
}

std::map<int,Arete> Graph::getMapArete()
{
    return m_Aretes;
}
