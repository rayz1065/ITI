{

Party Lamps (IOI 1998 Day 1 Task 3)

Copyright (C) 2002 Luca Foschini

This program is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.
	
This program is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License for more details.
	
You should have received a copy of the GNU General Public License along
with this program; see the file COPYING.  If not, write to the Free
Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
02111-1307, USA.  

}

{
Prima di leggere il codice si consiglia di dare un'occhiata a spiega.pdf
}

Program plamp;


const

{
poss contiene Le possibile configurazioni finali raggiungibili espresse come
numeri in base due su sei bit
}
   
   poss:array[0..7] of byte	      = (63,0,42,21,27,36,14,49);

{
nmosse contine le possibili configurazioni raggiungibili con 1 , 2 , o 3
o piu' mosse.

Ad esempio nmosse[2] contiene le possibili configurazioni finali
identificate dalla posizione nell'array poss raggiungibili avendo a
disposizione solo due mosse da compiere.

I -1 che compaiono sono sentinelle (delimitatori di fine riga)
}
   
   nmosse:array[1..3,0..8] of integer = ((1,2,3,4,-1,-1,-1,-1,-1),
					 (0,1,2,3,5,6,7,-1,-1),
					 (0,1,2,3,4,5,6,7,-1));
   
var Sfin    : string[6]; {La stringa pattern}
   N,C	    : longint;
   fin,fout : text;
	    
procedure ReadFile(var Fin: text);
var Off,On,i : integer;
begin
   readln(Fin,N);
   readln(Fin,C);

   {Tutte le possibili configurazioni finali sono raggiungibili con
   al piu' 3 mosse}

   if C>3 then C:=3;

   Sfin:='';for i:= 1 to 6 do Sfin:=Sfin+'?';
   
   read(Fin,on);
   while on>-1 do
   begin
      Sfin[(on-1) mod 6 +1]:='1';
      read(Fin,on);
   end;
   readln(Fin);

   read(Fin,off);
   while off>-1 do
   begin
      Sfin[(off-1) mod 6 +1]:='0';
      read(Fin,off);
   end
end; { ReadFile }

procedure writefile(var Fout :text );
var i,j,k    : longint;
   patt,mask : Byte;

begin	     
   i:=0;
   
   while Nmosse[C][i]>-1 do
   begin
      patt:=poss[Nmosse[C][i]];


{confronta ogni configurazione raggiungibile con C mosse con Sfin ,
la stringa pattern}
      
      j:=6;
      while (j>0) and ((sfin[j]='?') or
		       (ord(Sfin[j])-ord('0')=(patt and 1))) do
      begin
	 patt:=patt shr 1;
	 dec(j);
      end;


{Stampa la stringa se il confronto ha avuto successo}

      if j=0 then
      begin
	 patt:=poss[Nmosse[C][i]];
	 j:=0;
	 while (j<N) do
	 begin
	    mask:=1;mask:=mask shl 5;
	    for k:= 1 to 6 do
	    begin
	       inc(j);
	       if (patt and mask)>0 then
		  write(Fout,'1') else write(Fout,'0');
	       if j=n then break;
	       mask:=mask shr 1;
	    end;	    
	 end;
	 writeln(fout);
      end;
      inc(i);
   end;
   
end; { writefile }


{main}
begin
   Assign(Fin,'');reset(fin);
   readFile(Fin);Close(Fin);
   Assign(Fout,'');rewrite(fout);
   writefile(Fout);Close(Fout);
end.
