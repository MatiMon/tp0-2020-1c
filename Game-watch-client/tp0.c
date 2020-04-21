/*
 * main.c
 *
 *  Created on: 28 feb. 2019
 *      Author: utnso
 */

#include "tp0.h"

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip; // = "127.0.0.1";
	char* puerto; //= "4444";

	iniciar_logger();

	//Loggear "soy un log"

	leer_config();

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	//antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	ip = config_get_string_value(config, "IP");
	puerto = config_get_string_value(config, "PUERTO");
	conexion = crear_conexion(ip, puerto);
	log_info(logger, "Se realizo la conexion");

	/*char* mensaje;
	mensaje = readline(">");

	while (strcmp(mensaje, "")) {
			enviar_mensaje(mensaje, conexion);
			log_info(logger, "Se envio el mensaje: ");
			log_info(logger, mensaje);
			char * mensajeDevuelto = recibir_mensaje(conexion);
			log_info(logger, "Se recibio el mensaje: ");
			log_info(logger, mensajeDevuelto);

			free(mensaje);

			mensaje = readline(">");
		}
		free(mensaje);*/

	char * mensaje = "mensaje de prueba";
	enviar_mensaje("Soy un mensaje", conexion);
	log_info(logger, "Se envio un mensaje");

	char * mensajeDevuelto = recibir_mensaje(conexion);
	log_info(logger, mensajeDevuelto);

	log_info(logger, "Se termino el programa");

	terminar_programa(conexion, logger, config);
	log_destroy(logger);
	config_destroy(config);
}

/* CREAMOS LA FUNCION INICIAR_LOGGER QUE RECIBE: PATH, NOMBRE DEL ARCHIVO A CREAR, 1 (guardar en archivo e
imprimir por consola o 0 (guardar en archivo), LOG_LEVEL_INFO*/

void iniciar_logger(void)
{
	logger = log_create("/home/utnso/workspace/tp0/Game-watch-client/tp0.log", "tp0", 1, LOG_LEVEL_INFO);
	log_info(logger, "Soy un log");

}

void leer_config(void)
{
	char * clave;
	config = config_create("/home/utnso/workspace/tp0/Game-watch-client/tp0.config");
	clave = config_get_string_value(config, "CLAVE");

}

//TODO
void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	liberar_conexion(conexion);
	free(logger);
	free(config);
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
}

void leer_consola(void)
{
	char* leido;
	leido = readline(">");

	while (strcmp(leido, "")) {
		log_info(logger, leido);

		free(leido);

		leido = readline(">");
	}
	free(leido);

		//free NO asigna el valor NULL a los punteros que libera, pero es buena practica asignarselo a tenerlo apuntando a basura

}
