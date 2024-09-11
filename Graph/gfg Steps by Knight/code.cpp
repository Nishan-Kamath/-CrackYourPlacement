class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	struct Cell {
        int x, y, dist;
        Cell(int x, int y, int dist) : x(x), y(y), dist(dist) {}
    };

    bool isValid(int x, int y, int N) {
    // Check if the position is within the bounds of the chessboard
        return (x >= 1 && x <= N && y >= 1 && y <= N);
    }

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
    // Possible moves for a knight
        int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
        int dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
    
        // Visited array to keep track of visited positions
    vector<vector<bool>> visited(N + 1, vector<bool>(N + 1, false));
    
    // Queue for BFS, initialized with the starting position of the knight
    queue<Cell> q;
    q.push(Cell(KnightPos[0], KnightPos[1], 0));
    
    // Mark the starting position as visited
    visited[KnightPos[0]][KnightPos[1]] = true;
    
    // BFS loop
    while (!q.empty()) {
        Cell current = q.front();
        q.pop();
        
        // If the current position is the target position, return the distance (steps)
        if (current.x == TargetPos[0] && current.y == TargetPos[1]) {
            return current.dist;
        }
        
        // Explore all 8 possible moves
        for (int i = 0; i < 8; i++) {
            int newX = current.x + dx[i];
            int newY = current.y + dy[i];
            
            // If the new position is valid and not yet visited, enqueue it
            if (isValid(newX, newY, N) && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push(Cell(newX, newY, current.dist + 1));
            }
        }
    }
    
    // If the target is unreachable (should not happen for valid input)
    return -1;
}
};