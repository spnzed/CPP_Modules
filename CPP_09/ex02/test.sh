#!/bin/bash

# Códigos de color ANSI
RED='\033[1;31m'
GREEN='\033[1;32m'
YELLOW='\033[1;33m'
BLUE='\033[1;34m'
CYAN='\033[1;36m'
WHITE='\033[1;37m'
RESET='\033[0m'

# Verificar que existe un Makefile en el directorio actual
if [ ! -f Makefile ]; then
    echo -e "${RED}Error: No se encontró un Makefile en el directorio actual.${RESET}"
    exit 1
fi

# Ejecutar `make`
echo -e "${CYAN}Ejecutando make...${RESET}"
if ! make; then
    echo -e "${RED}Error: make falló.${RESET}"
    exit 1
fi

# Definir los conjuntos de inputs
declare -a inputs=(
    Funciona
    "9 8 7 6 15 5 4 13 3 2 14 1 12 10"
    "100 99 98 97 96 95 94 93 92 91 90"
    "100000 99999 99998 99997 99996 99995 99994"
    "10 5 1"
    "1000000 500000 250000 125000 62500 31250"
    "11 22 33 44 55 66 77"

    No funciona
    "23 1 56 3 45 78 4 6 9 10 2"
    "100 1 50 99 2 98 3 97 4 96 5"
    "1 100 50 25 75 10 90 5 95"
)

# Función para ordenar números y formatearlos como el output esperado
ordenar_numeros() {
    echo "$@" | tr ' ' '\n' | sort -n | awk '{printf "[%s] ", $1}' | sed 's/ $//'
}

# Variables para resultados
total_tests=${#inputs[@]}
passed_tests=0
failed_tests=0

# Almacenar información de las pruebas fallidas
declare -a failed_cases=()

# Realizar pruebas
for i in "${!inputs[@]}"; do
    input_string="${inputs[$i]}"
    expected_output=$(ordenar_numeros $input_string)

    # Contar la cantidad de números en los inputs
    input_count=$(echo "$input_string" | wc -w)

    # Ejecutar el programa con los inputs
    echo -e "${BLUE}Ejecutando prueba $((i+1))/$total_tests con ${CYAN}$input_count${RESET} ${WHITE}números.\tInput:${RESET} ${YELLOW}$input_string${RESET}"
    actual_output=$(./PmergeMe $input_string)

    # Comparar resultados
    if [ "$actual_output" == "$expected_output" ]; then
        echo -e "${GREEN}✅ Prueba $((i+1)): PASÓ${RESET}"
        ((passed_tests++))
    else
        echo -e "${RED}❌ Prueba $((i+1)): FALLÓ${RESET}"
        failed_cases+=("${CYAN}Prueba $((i+1)):${RESET}\n${WHITE}Inputs:${RESET} ${YELLOW}$input_string${RESET}\n${WHITE}Esperado:${RESET} ${GREEN}$expected_output${RESET}\n${WHITE}Generado:${RESET} ${RED}$actual_output${RESET}")
        ((failed_tests++))
    fi
    echo "---------------------------------"
done

# Mostrar resumen
echo -e "${CYAN}Resumen de pruebas:${RESET} ${GREEN}$passed_tests${RESET}/${total_tests} PASARON"
if [ "$failed_tests" -gt 0 ]; then
    echo -e "${YELLOW}⚠️ Algunas pruebas fallaron:${RESET}"
    for case in "${failed_cases[@]}"; do
        echo -e "$case"
        echo "---------------------------------"
    done
else
    echo -e "${GREEN}🎉 Todas las pruebas pasaron exitosamente.${RESET}"
fi

exit 0
