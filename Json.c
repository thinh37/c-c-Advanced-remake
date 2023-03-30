/*
* File: Json.c
* Author: Quach Minh Thinh
* Date: 30/03/2023
* Description: This is a sample file for Json program
*/
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
typedef enum {
    JSON_NULL,
    JSON_BOOLEAN,
    JSON_NUMBER,
    JSON_STRING,
    JSON_ARRAY,
    JSON_OBJECT
} JsonType;

typedef struct JsonValue {
    JsonType type;
    union {
        int boolean;
        double number;
        char *string;
        struct {
            struct JsonValue *values;
            size_t count;
        } array;
        struct {
            char **keys;
            struct JsonValue *values;
            size_t count;
        } object;
    } value;
} JsonValue;

/*
* Function: type_string
* Description: This function 
* Input:
*   json_object -  json_object char pointer to pointer
* Output:
*   return the string put out form json_object
*/
char *type_string(char **json_object){
    char *value = (char*)malloc(sizeof(char));
    int i = 0;
    if(**json_object == '\"') (*json_object)++;
    if(**json_object == ' ') (*json_object)++;
        while ((**json_object != '\"'))
        {
            value[i] = *((*json_object)++);
            i++;
            value = (char*)realloc(value, (i+1)*sizeof(char));
        }
        value[i]='\0';
    if(**json_object == '\"') (*json_object)++;
    return value;
}
char *json_object = "{\"ten\":\"Nguyen A\", \"tuoi\": 19, \"diachi\": \"HCM\"}";
/*
* Function: parse_json
* Description: This function 
* Input:
*   json_object - a char pointer 
* Output:
*   return the key and value of json_object
*/
void parse_json(char *json_object){

    char key[10];
    char value[20];
    int i = 0;
    while (*json_object != '}')
    {
        if(*json_object == '{') json_object++;
        if(*json_object == ',') json_object++;
        if(*json_object ==' ') json_object++;
        strcpy(key, type_string(&json_object));
        if(*json_object == ':') json_object++;
        if(*json_object == ' ') json_object++;
        strcpy(value, type_string(&json_object));
        printf("Key: %s, value: %s\n", key, value);
    }
}


int main(int argc, char const *argv[])
{
    parse_json(json_object);
    return 0;
}
