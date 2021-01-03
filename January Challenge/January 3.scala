object Solution {
    def countArrangement(n: Int): Int = {
        var count=0
        
        def loop(i: Int, n: Int, pos: Int, visited: scala.collection.mutable.ArrayBuffer[Boolean]): Unit = {
            if(i<=n)
            {
                if (visited(i)==false && (pos%i == 0 || i%pos == 0))
                {
                    visited(i)=true
                    calculate(n,pos+1,visited)
                    visited(i)=false
                }
                loop(i+1,n,pos, visited)
            }
        }
        
        def calculate(n: Int, pos: Int, visited: scala.collection.mutable.ArrayBuffer[Boolean]) = {
            if(pos>n)
                count=count+1
            loop(1,n,pos,visited)
            
        }
        var visited = scala.collection.mutable.ArrayBuffer.fill(n+1)(false)
        calculate(n,1,visited)
        count
    }
}