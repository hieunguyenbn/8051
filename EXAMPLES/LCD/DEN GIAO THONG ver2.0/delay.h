void delays( unsigned int u)
{
   unsigned int t,i;
   for(t=0;t<u;t++)
   {
      for(i=0;i<33000;i++);
   }
}
void delayms( unsigned int u)
{
   unsigned int t,i;
   for(t=0;t<u;t++)
   {
      for(i=0;i<330;i++);
   }
}
void delayus( unsigned int u)
{
   unsigned int t,i;
   for(t=0;t<u;t++)
   {
      for(i=0;i<3;i++);
   }
}