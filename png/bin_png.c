#include <fcntl.h>
#include <unistd.h>
#include <png.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

#define LARGEUR 512

void octet_vers_rgb(unsigned char octet, unsigned char *r, unsigned char *g, unsigned char *b)
{
    *r = octet;
    *g = (octet % 128) * 2;
    *b = 255 - octet;
}

char *nom_sortie(const char *chemin)
{
    const char *nom = strrchr(chemin, '/');
    nom = nom ? nom + 1 : chemin;
    char *sortie = malloc(strlen(nom) + 5);
    if (!sortie)
        return NULL;
    sprintf(sortie, "%s.png", nom);
    return sortie;
}

int main(int argc, char **argv)
{
    if (argc < 2 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)
    {
        printf("Usage: %s <fichier>\n", argv[0]);
        return 0;
    }

    struct stat infos;
    if (stat(argv[1], &infos) != 0)
    {
        fprintf(stderr, "Impossible d'ouvrir: %s\n", argv[1]);
        return 1;
    }

    long taille = infos.st_size;
    int hauteur = (taille / LARGEUR) + 1;

    unsigned char *octets = calloc(taille, 1);
    unsigned char *pixels = calloc(LARGEUR * hauteur * 3, 1);
    if (!octets || !pixels)
    {
        free(octets);
        free(pixels);
        fprintf(stderr, "Erreur d'allocation memoire\n");
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0)
    {
        free(octets);
        free(pixels);
        fprintf(stderr, "Impossible de lire: %s\n", argv[1]);
        return 1;
    }
    read(fd, octets, taille);
    close(fd);

    for (long i = 0; i < taille; i++)
    {
        unsigned char r, g, b;
        octet_vers_rgb(octets[i], &r, &g, &b);
        pixels[i * 3 + 0] = r;
        pixels[i * 3 + 1] = g;
        pixels[i * 3 + 2] = b;
    }

    free(octets);

    char *fichier_png = nom_sortie(argv[1]);
    if (!fichier_png)
    {
        free(pixels);
        return 1;
    }

    png_image image;
    memset(&image, 0, sizeof(image));
    image.version = PNG_IMAGE_VERSION;
    image.width = LARGEUR;
    image.height = hauteur;
    image.format = PNG_FORMAT_RGB;

    if (!png_image_write_to_file(&image, fichier_png, 0, pixels, 0, NULL))
        fprintf(stderr, "Erreur ecriture png: %s\n", image.message);
    else
        printf("Written `%s'.\n", fichier_png);

    free(pixels);
    free(fichier_png);
    return 0;
}
