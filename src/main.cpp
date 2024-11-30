#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

// Fonction de callback pour redimensionner la fenêtre
void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int main()
{
    // Initialisation de GLFW
    if (!glfwInit())
    {
        std::cerr << "GLFW initialization failed!" << std::endl;
        return -1;
    }

    // Création de la fenêtre GLFW
    GLFWwindow *window = glfwCreateWindow(800, 600, "Triangle OpenGL", nullptr, nullptr);
    if (!window)
    {
        std::cerr << "Window initialization failed!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    // Initialisation de GLAD
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cerr << "GLAD initialization failed!" << std::endl;
        return -1;
    }

    // Configuration de la taille de la fenêtre
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Définition des données du triangle
    float vertices[] = {
        // Positions des sommets (x, y)
        -0.5f, -0.5f, // Sommet bas gauche
        0.5f, -0.5f,  // Sommet bas droite
        0.0f, 0.5f    // Sommet haut
    };

    // Création du VBO (Vertex Buffer Object) et du VAO (Vertex Array Object)
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Lier le VAO
    glBindVertexArray(VAO);

    // Lier le VBO et envoyer les données des sommets
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    // Définir le format des données des sommets
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);

    // Débinder
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Boucle de rendu
    while (!glfwWindowShouldClose(window))
    {
        // Effacer l'écran avec une couleur
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Dessiner le triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glBindVertexArray(0);

        // Échanger les buffers et traiter les événements
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Nettoyage
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
