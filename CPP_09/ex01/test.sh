#!/bin/bash

# Colores
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # Sin color

# Contadores de tests
PASSED=0
FAILED=0

# Función para ejecutar un test
run_test() {
    local test_input="$1"
    local expected_output="$2"
    local test_description="$3"

    # Ejecutar el programa
    actual_output=$(./RPN "$test_input" 2>&1)
    
    if [[ "$actual_output" == "$expected_output" ]]; then
        echo -e "${GREEN}PASSED${NC}: $test_description"
        ((PASSED++))
    else
        echo -e "${RED}FAILED${NC}: $test_description"
        echo -e "    Input:    '$test_input'"
        echo -e "    Expected: '$expected_output'"
        echo -e "    Got:      '$actual_output'"
        ((FAILED++))
    fi
}

# Ejecutar Make para compilar el proyecto
echo -e "${YELLOW}Compilando el proyecto...${NC}"
make > /dev/null 2>&1

# Verificar si la compilación fue exitosa
if [[ $? -ne 0 ]]; then
    echo -e "${RED}Error: Falló la compilación.${NC}"
    exit 1
fi

# Tests básicos
echo -e "${YELLOW}Ejecutando tests básicos...${NC}"
run_test "3 4 +" "7" "Suma básica"
run_test "2 1 -" "1" "Resta básica"
run_test "6 3 *" "18" "Multiplicación básica"
run_test "8 2 /" "4" "División básica"

# Tests combinados
echo -e "${YELLOW}Ejecutando tests combinados...${NC}"
run_test "3 4 + 2 *" "14" "Suma y multiplicación"
run_test "5 1 2 + 4 * + 3 -" "14" "Expresión RPN compleja"
run_test "2 3 4 * +" "14" "Prioridad implícita"
run_test "7 8 + 3 2 + /" "3" "División después de suma"

# Tests de errores
echo -e "${YELLOW}Ejecutando tests de errores...${NC}"
run_test "3 4 & +" "Error: Character is neither a number nor a valid operator." "Carácter inválido (&)"
run_test "3   4  +" "7" "Espacios adicionales"
run_test "3 4" "Error: Not enough operators" "Falta de operadores"
run_test "3 +" "Error: Not enough operators" "Falta de operandos"
run_test "3 0 /" "Error: Division 0" "División por cero"
run_test "1 2 3 +" "Error: Not enough operators" "Falta de operadores al final"

# Test de validación de un solo dígito
echo -e "${YELLOW}Ejecutando test de validación de un solo dígito...${NC}"
run_test "12 3 +" "Error: Only single-digit numbers are allowed." "Número de dos dígitos"
run_test "1 2 3 +" "Error: Not enough operators" "Falta de operadores con número adicional"

# Tests de límites
echo -e "${YELLOW}Ejecutando tests de límites...${NC}"
run_test "1 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 +" "45" "Secuencia larga de sumas"
run_test "9 1 -" "8" "Resta de dos números menores a 10"
run_test "8 7 *" "56" "Multiplicación de dos números menores a 10"
run_test "9 3 /" "3" "División de números menores a 10"
run_test "2" "2" "Un solo número (error)"
run_test "+" "Error: Not enough operators" "Un solo operador (error)"

# Tests extras
echo -e "${YELLOW}Ejecutando tests extras...${NC}"
run_test "1 1 + 2 * 3 *" "12" "Operaciones múltiples consecutivas"
run_test "5 3 2 * +" "11" "Operadores al final"
run_test "3 5 + 7 * 2 -" "54" "Expresión compleja"
run_test "3 3 3 3 + + +" "12" "Sumas consecutivas"
run_test "2 2 2 * *" "8" "Multiplicaciones consecutivas"
run_test "5 1 2 + 4 * + 3 - 2 +" "16" "Expresión extendida con prioridad implícita"
run_test "9 6 - 3 +" "6" "Resta seguida de suma"

# Nuevos tests propuestos
echo -e "${YELLOW}Ejecutando nuevos tests...${NC}"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42" "Expresión larga con multiplicación y resta"
run_test "7 7 * 7 -" "42" "Multiplicación y resta"
run_test "1 2 * 2 / 2 * 2 4 - +" "0" "Operaciones complejas con multiplicación y división"
run_test "2 3 7 * 8 5 3 6 2 + * 4 - 3 7 + / + - * *" "42" "Expresión compleja con múltiples operaciones"
run_test "1 2 3 4 5 6 7 8 9 + - + - + - + - 9 8 7 6 5 4 3 2 1 - + - + - + - + -" "0" "Secuencia larga de sumas y restas"
run_test "4 2 5 * + 1 3 2 * + / 8 5 + + 2 1 * *" "30" "Expresión compleja con multiplicaciones y divisiones"
run_test "3 2 3 2 2 * + * * 7 2 * - 6 2 4 * + /" "2" "Combinación de multiplicaciones y divisiones"
run_test "2 5 6 3 / 8 * - + 3 - 3 * 5 4 + * 9 /" "-36" "Expresión con divisiones y multiplicaciones"
run_test "2 2 * 3 + 5 * 4 -" "31" "Operaciones básicas con multiplicaciones y sumas"
run_test "3 2 3 2 2 * + * * 7 2 * -" "28" "Combinación de multiplicaciones y restas"
run_test "1" "1" "Un solo número"

# Test de expresiones inválidas
echo -e "${YELLOW}Ejecutando tests de expresiones inválidas...${NC}"
run_test "10" "Error: Only single-digit numbers are allowed." "Número mayor a 9"
run_test "28 6 2 4 * + /" "Error: Only single-digit numbers are allowed." "Número mayor a 9"
run_test "" "Error: Invalid input" "Expresión vacía"
run_test "+" "Error: Not enough operators" "Solo operador"
run_test "1 1" "Error: Not enough operators" "Faltan operadores"
run_test "1 1 + +" "Error: Not enough operators" "Operadores consecutivos"
run_test "4 2 5 * + 1 3 2 * * + / 8 5 + + 2 1 * *" "Error: Not enough operators" "Expresión mal formada operadores de más"
run_test "2 3 7 * 8 5 3 6 2 + * 4 - 2 3 7 + / + - * *" "Error: Not enough operators" "Expresión mal formada"
run_test "9 9 - 8 2 3 + * 5 2 2 2 * * * - /" "Error: Division 0" "División por cero"
run_test "5 0 /" "Error: Division 0" "División por cero"

# Resumen final
echo -e "${YELLOW}Resumen de pruebas:${NC}"
echo -e "${GREEN}PASSED:${NC} $PASSED"
echo -e "${RED}FAILED:${NC} $FAILED"

if [[ $FAILED -eq 0 ]]; then
    echo -e "${GREEN}¡Todas las pruebas pasaron exitosamente!${NC}"
else
    echo -e "${RED}Algunas pruebas fallaron. Revisa los detalles arriba.${NC}"
fi
