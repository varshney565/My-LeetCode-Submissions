impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let n = height.len();
        let mut i = 0;
        let mut j = n-1;
        let mut ans = 0;
        while(i < j){
            let val = (j-i) as i32 * height[j].min(height[i]);
            ans = ans.max(val);
            if height[i] < height[j] {
                i += 1;
            }
            else { 
                j -= 1;
            }
        }
        ans
    }
}