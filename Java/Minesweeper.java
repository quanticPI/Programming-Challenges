import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Main {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException{
		Main mines = new Main();
		mines.Begin();
	}
	
	void Begin() throws IOException{
		//Scanner in = new Scanner(System.in);
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] l;
		String line;
		int f,c,fila,col;	
		int field = 1;
		char token;
		
		line = in.readLine().trim();
		while(line.compareTo("")==0)
			line = in.readLine().trim();
		
		while(line != null){		
			//line = line.replaceAll("", "\n");
			l = line.trim().split(" "); 
			f = Integer.parseInt(l[0]);
			c = Integer.parseInt(l[1]);
			// vacio?
			if(f == 0 && c == 0)
				break;
			char salida[][] = new char[f+2][c+2];

			
			for(fila=0; fila<(f+2); fila++) 
				for (col=0; col < c+2; col++)					
					salida[fila][col]='0';

			for(fila=0; fila<f; fila++){
				line = in.readLine();
				for(col =0; col<c; col++){
					token = line.charAt(col);
					if(token == '*'){
						salida[fila+1][col+1] = '*';
						for(int i=-1; i<2; i++)
							for(int j=-1; j<2; j++)
								if (salida[fila+1+i][col+1+j]!='*') 
									salida[fila+1+i][col+1+j] = (char)((int)salida[fila+1+i][col+1+j] + 1);							
					}						
				}
			}			
			System.out.println("Field #" + field++ +":");
			for (int i=0;i<f;i++){ 
				for(int j=0;j<c;j++) 						
					System.out.print(salida[1+i][1+j]);		
				System.out.println();
			}
			
			line = in.readLine().trim();
			if(line.compareTo("0 0") != 0)
				System.out.println();
			//}
		} // end while

	}

}
