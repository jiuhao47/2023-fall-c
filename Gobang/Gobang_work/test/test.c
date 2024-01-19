void link_insert(STU **p_head, STU *p_new)
{
    STU *pb = NULL, *pf = NULL;
    pf = *p_head;
    if (*p_head == NULL)
    { // 1.头结点为空，直接插入
        *p_head = p_new;
        p_new->next = NULL;
        return;
    }

    while ((p_new->num >= pf->num) && (pf->next != NULL))
    { // 2.遍历
        pb = pf;
        pf = pf->next;
    }

    if (p_new->num < pf->num)
    { // 3.找到一个pf指向的节点的num比新来的节点的num大，则插到pf节点的前面。
        if (pf == *p_head)
        { // 3.1.找的节点是头结点，插到对前面
            *p_head = p_new;
            p_new->next = pf;
        }
        else
        { // 3.2.找到的是中间节点，插在中间节点pf的前面
            pb->next = p_new;
            p_new->next = pf;
        }
    }
    else
    { // 4.没有找到一个节点的num比新来的节点的num大，插在末尾
        pf->next = p_new;
        p_new->next = NULL
    }
}