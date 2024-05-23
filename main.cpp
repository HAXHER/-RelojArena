#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

int main() 
 {
     int suma_especifica = 0;
     int suma[100];
     int contador = 0;
     int maximo =0;
     
    std::ifstream archivo("archivo.txt");
    std::vector<std::vector<int>> matriz;

        if (!archivo) 
        {
          std::cerr << "No se pudo abrir el archivo." << std::endl;
          return 1;
        }

    std::string linea;

     
        while (std::getline(archivo, linea)) 
         {
            std::vector<int> fila;
            std::stringstream ss(linea);
             
                 int numero;
              while (ss >> numero) 
              { 
                fila.push_back(numero);
              }
          matriz.push_back(fila);
         }

    archivo.close();

    std::cout << "Contenido de la matriz:" << std::endl;
     
        for (const auto& fila : matriz) 
         {
            for (int numero : fila) 
              {
                std::cout << numero << " ";
              }
            std::cout << std::endl;
         }

     
      
        for (int i = 0; i < matriz.size(); i++) 
         {
            for (int j = 0; j < matriz[i].size(); j++) 
            {
               if(i>0 && j > 0 && i < matriz.size() - 1 && j < matriz[i].size() - 1)
                 {
                      suma_especifica = matriz[i-1][j-1] + matriz[i-1][j] + matriz[i-1][j+1] + 
                      matriz[i][j] + 
                      matriz[i+1][j-1] + matriz[i+1][j] + matriz[i+1][j+1];
              
                      suma[contador] = suma_especifica;
                         std::cout << "-------------------------------------------------------------" 
                         << std::endl;
                         std::cout << "-La suma de las posiciones especificadas en la matriz es: " << 
                         suma[contador] << std::endl;
                     contador++;
                 }
             }
        
         }

         for(int i = 0; i < contador; i++)
          {
              
            if(suma[i] > maximo)
             {
                 maximo=suma[i];
             }
          }


    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "--->La suma maxima de los relojes es: " << maximo << std::endl;
     
  return 0;
 }

//Si ves esto no le muevas JAJAJAJAJAJ 