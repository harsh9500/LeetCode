object Solution {
    def canFormArray(arr: Array[Int], pieces: Array[Array[Int]]): Boolean = {
        var mp = scala.collection.mutable.Map[Int,Array[Int]]()
        pieces.map(x => mp += (x(0)->x) )
        
        var res = scala.collection.mutable.ArrayBuffer[Int]()
        arr.map(ele => mp.getOrElse(ele,Array[Int]()).map(x => res += x))
        
        return res.sameElements(arr)
    }
}