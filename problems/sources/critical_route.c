ArrayList* reachble_cities(Graph *g, Graph *atual){
    if(!g || !atual){
        return NULL;
    }
    ArrayList *l = newList();
    if(!atual->edges)
        return l;
    l = addList(l, atual->edges->to);
    ArrayList *p = l;
    Graph *aux;
    while(p){
        aux = findGraph(g, p->id);
        if(!aux){
            p = p->prox;
            continue;
        }
        Edge *v = aux->edges;
        while(v){
            l = add_if_not_existList(l, v->to);
            v = v->next;
        }
        p = p->next;
    }
    return l;
}

void criticalRoute(Graph* g, char* captital){
  t = g;
  while(t){
      Edge *v1 = NULL, *v2 = NULL;
      v1 = t->edges;
      while(v1){
          v2 = v1->next;
          char *city_name = (char*) malloc(sizeof(char)*200);
          strcpy(city_name, v1->to);
          disconnectGraph(g, t->id, v1->to);
          ArrayList *l = reachble_cities(g, t);

          if(!findList(l, capital)){
              printf("[%s %s] \n", t->id, city_name);
          }
          connectGraph(g, t->id, city_name);
          v1 = v2;
          destroyList(l);
          free(city_name);
          if(!v1){
              break;
          }
          v2 = v1->next;
      }
      t = t->next;
    }
}
