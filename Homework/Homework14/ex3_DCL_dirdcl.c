void dirdcl(void)
{
    int type;
    if (tokentype == '(')
    {
        dcl();
        if (tokentype != ')')
        {
            printf("error: missing )\n");
        }
    }
    else if (tokentype == NAME)
    {
        strcpy(name, token);
    }
    else
    {
        printf("error: expected name of (dcl)\n");
    }
    while ((type = gettoken()) == PARTENS || type == BRACKETS)
    {
        if (type == PARTENS)
        {
            strcat(out, " function returning");
        }
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
}