const dx = [1, 0, -1, 0];
const dy = [0, 1, 0, -1];

function solution(maps) {
    var answer = -1;
    let queue = [];
    let vis = Array.from({length: 100}, () => new Array(100).fill(0));
    queue.push({x: 0,y: 0});
    vis[0][0] = 1;
    
    while (queue.length > 0) {
        let cur = queue[0];
        queue.shift();
        if (cur.x == maps.length - 1 && cur.y == maps[0].length - 1) {
            answer = vis[cur.x][cur.y];
            break;
        }
        
        for (let dir = 0; dir < 4; dir++) {
            let nx = cur.x + dx[dir];
            let ny = cur.y + dy[dir];
            
            if (nx < 0 || ny < 0 || nx >= maps.length || ny >= maps[0].length) continue;
            if (vis[nx][ny] > 0) continue;
            if (maps[nx][ny] == 0) continue;
            
            queue.push({x: nx, y: ny});
            vis[nx][ny] = vis[cur.x][cur.y] + 1;
            if (nx == maps.length - 1 && ny == maps[0].length - 1) {
                break;
            }
        }
    }
    
    return answer;
}